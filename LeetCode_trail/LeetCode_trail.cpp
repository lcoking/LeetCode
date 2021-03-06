// LeetCode_trail.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"





/**
 *      lock_guard test
 */

std::mutex  my_lock;

void add(int &num, int &sum)
{
    while (true)
    {
        std::lock_guard<std::mutex> lock(my_lock);
        if (num < 100)
        {
            num += 1;
            sum += num;
        }
        else
        {
            break;
        }
    }
}


int lock_guard_test()
{
	int sum = 0;
	int num = 0;

	std::vector<std::thread> ver;
	for (int i = 0; i < 20; ++i)
	{
		std::thread t(add, std::ref(num), std::ref(sum));
		ver.emplace_back(std::move(t));
	}

	std::for_each(ver.begin(), ver.end(), std::mem_fn(&std::thread::join));
	std::cout << "The result is : " << sum << std::endl;

    return 0;
}



/*
*       unique_lock test
*/

std::mutex          mtx;
std::once_flag      flag;


void print_block(int n, char c)
{
    //  unique_lock有多组构造函数, 这里std::defer_lock不设置锁状态
    std::unique_lock<std::mutex> amy_lock(mtx, std::defer_lock);     //  std::defer_lock 不设置锁状态

	//  尝试加锁, 如果加锁成功则执行
	//  (适合定时执行一个job的场景, 一个线程执行就可以, 可以用更新时间戳辅助)
    if (amy_lock.try_lock())
    {
        for (int i = 0; i< n; ++i)
        {
            std::cout << c << std:: endl;
        }
    }

}

void run_one(int &n)
{
    std::call_once(flag, [&n] {n = n + 1; });   //  只执行一次, 适合延迟加载; 多线程static变量情况
}


int unique_lock_test()
{
    std::vector<std::thread> ver;
    int num = 0;
    for (auto i = 0; i < 10; ++i)
    {
        ver.emplace_back(print_block, 50, '*');
        ver.emplace_back(run_one, std::ref(num));
    }

    for (auto &t:ver)
    {
        t.join();
    }

    std::cout << "The result is :" << num << std::endl;

    return 0;
}



/*
*       call_once test
*/

std::once_flag  flag1;
std::once_flag  flag2;

void simple_do_once()
{
    std::call_once(flag1, []() {std::cout << "Simple example : called once." << std::endl; });
}

void may_throw_function(bool do_throw)
{
    if (do_throw)
    {
        std::cout << "Throw: call_once will retry." << std::endl;   //  this may appear more than once
        throw std::exception();
    }

    std::cout << "Don't throw, call_once is called and will not try again." << std::endl;    //  guaranteed once
}

void do_once(bool do_throw)
{
    try
    {
        std::call_once(flag2, may_throw_function, do_throw);    //  EXCP
    }
    catch (...)
    {
    	
    }

}

int call_once_test()
{
    /* 无异常情况下, lambda 形式的 callable object 调用一次后, 其余调用均立刻返回 */
    std::vector<std::thread> vec;
    for (auto i = 0; i < 6; ++i)
    {
        std::thread st(simple_do_once);
        vec.emplace_back(std::move(st));    //  std::thread 只有 move constructor 无 copy constructor
    }

    for (auto &t:vec)
    {
        t.join();
    }

    /* 异常抛出, flag 不变 */
    std::vector<std::thread> vec2;
    for (auto i = 0; i < 5; ++i)
    {
        std::thread t(do_once, true);       //  EXCP

        vec2.emplace_back(std::move(t));    
         

    }
    vec2.emplace_back(std::thread(do_once, false));
    vec2.emplace_back(std::thread(do_once, true));  //  EXCP


    for (auto &t:vec2)
    {
        t.join();
    }

    return 0;

}




/*
 *      在 constructor 中创建&启动线程是不安全的
 *      -在initialization list 中启动 thread,   不安全
 */
class MyClass
{
public:
    MyClass():m_isExit(false), m_thread(&MyClass::threadMain, this)
    {

    }

    ~MyClass()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_isExit = true;
        m_condition.notify_one();
        lock.unlock();
        if (m_thread.joinable())
        {
            m_thread.join();
        }
    }

    void addTask(int taskToAdd)
    {
        std::lock_guard<std::mutex> lock_guard(m_mutex);
        m_taskQueue.push(taskToAdd);
        m_condition.notify_one();
    }
protected:
private:
    void threadMain()
    {
        while (true)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_condition.wait(lock, [&] {return !m_taskQueue.empty() || m_isExit; });

            if (m_isExit)
            {
                std::cout << "Thread exit..." << std::endl;
                break;
            }

            int64_t task = std::move(m_taskQueue.front());
            m_taskQueue.pop();
            lock.unlock();
            std::cout << "One task was taken: No." << task << std::endl;
            //  ...
        }
    }

    bool                        m_isExit;
    std::thread                 m_thread;
    std::mutex                  m_mutex;
    std::condition_variable     m_condition;
    std::queue<int64_t>         m_taskQueue;
};



int constructor_init_thread_test()
{
    MyClass myclass;
    for (int i = 0; i < 100; ++i)
    {
        myclass.addTask(i);
        std::cout << "任务已经添加: " << i << std::endl;
    }
    return 0;
}


/*
 *      在 constructor 中创建&启动线程是不安全的
 *      -在基类constructor 中启动 thread,   不安全
 *      在有继承结构时，有虚成员函数时，绝对不要在构造函数中启动线程
 */


class MyClass2
{
public:
    MyClass2() :m_isExit(false)
    {
        m_thread = std::thread(&MyClass2::threadMain, this);
    }

    ~MyClass2()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_isExit = true;
        m_condition.notify_one();
        lock.unlock();
        if (m_thread.joinable())
        {
            m_thread.join();
        }
       
    }

    void addTask(int taskToAdd)
    {
        std::lock_guard<std::mutex> alock_guard(m_mutex);
        m_taskQueue.push(taskToAdd);
        m_condition.notify_one();
    }

private:
    virtual void threadMain() = 0;
    std::thread m_thread;

protected:
    std::mutex              m_mutex;
    std::condition_variable m_condition;
    bool                    m_isExit;
    std::queue<int>         m_taskQueue;
};

class Derived :public MyClass2
{
    virtual void threadMain()
    {
        while (true)
        {
            std::unique_lock < std::mutex > lock(m_mutex);
            m_condition.wait(lock, [&] {return !m_taskQueue.empty() || m_isExit; });

            if (m_isExit)
            {
                std::cout << "线程退出..." << std::endl;
                break;
            }

            //  取出任务
            int task = std::move(m_taskQueue.front());
            m_taskQueue.pop();
            lock.unlock();
            std::cout << "One task was taken, No. " << task << std::endl;

        }
    }
};

int constructor_init_thread_test2()
{
    Derived derived;
    for (int i = 0; i < 100; ++i)
    {
        derived.addTask(i);
        std::cout << "Task No." << i << " is added." << std::endl;
    }

    return 0;
}


/*
 *      在 constructor 中创建&启动线程是不安全的
 *      -两段式启动是安全的
 *      -constructor 负责初始化成员变量
 *      -start() 方法来启动线程
 */


class Demo
{
public:
    Demo() : m_isExit(false)
	{
		std::cout << "Base-Class object constructing..." << std::endl;
	}

	~Demo()
	{
		std::unique_lock<std::mutex> lock(m_mutex);    //m_isExit是多线程共享的，需要加锁再修改
		m_isExit = true;
		m_condition.notify_one();
		lock.unlock();
		if (m_thread.joinable())
			m_thread.join();
	}

	void start()
	{
		m_thread = std::thread(&Demo::threadMain, this); //启动线程
	}

	void addTask(int taskToAdd)
	{
		std::lock_guard<std::mutex> lock_guard(m_mutex);
		m_taskQueue.push(taskToAdd);
		m_condition.notify_one();
	}

private:
	virtual void threadMain() = 0;  //线程入口函数
protected:
	std::thread                 m_thread;
	std::mutex                  m_mutex;        //互斥锁
	std::condition_variable     m_condition;    //条件变量
	bool                        m_isExit;       //退出标志，置为true时，线程需要退出
	std::queue<int>             m_taskQueue;    //任务队列，元素类型只是简单的 int
};

class DemoDerived :public Demo
{
public:
    DemoDerived()
    {
        std::cout << "Derived-Class object constructing...";
    }

private:
    virtual void threadMain()
    {
		while (1) 
        {
			std::unique_lock<std::mutex> lock(m_mutex);
			m_condition.wait(lock, [&] { return !m_taskQueue.empty() || m_isExit; });    //任务队列中有任务待处理 或者 线程需要退出时唤醒线程
																						 //线程被唤醒，处理任务，或者退出
			if (m_isExit) {
				//线程需要退出，中断循环
				std::cout << "线程退出..." << std::endl;
				break;
			}
			//取出任务
			int task = std::move(m_taskQueue.front());
			m_taskQueue.pop();
			lock.unlock();
			std::cout << "一个任务被取出：" << task << std::endl;
			// 处理任务
			// ...
		}

    }
};

class ThreadHandler
{
public:
    ThreadHandler()
    {
        derived.start();
    }

    void addTask(int taskToAdd)
    {
        derived.addTask(taskToAdd);
    }

private:
    DemoDerived derived;
};



int thread_start_recommended_test()
{
    ThreadHandler thdlr;
    for (int i = 0; i < 125; ++i)
    {
        thdlr.addTask(i);
        std::cout << "Task No." << i << " is added to the queue." << std::endl;
    }

    return 0;
}


/*
 *   
 */

int main()
{
    //lock_guard_test();
    //unique_lock_test();
    //call_once_test();
    //constructor_init_thread_test2();
    thread_start_recommended_test();
    return 0;
}




