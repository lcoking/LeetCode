
#include "Header.h"


int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();


int Leet_Solution::searchInsert(std::vector<int> &nums, int target)
{
	unsigned long bottom = 0;
	unsigned long top = (nums.size() - 1);

	//
	while (bottom<=top)
	{
		int mid = bottom + (top - bottom) / 2;
		if (nums[mid]<target)
		{
			bottom = mid + 1;
		}
		else
		{
			top = mid - 1;
		}
	}
	return bottom;
}

std::string Leet_Solution::addString(std::string num1, std::string num2)
{
	if (num1.length() < num2.length())
	{
		swap(num1, num2);	//交换内容
	}

	bool bcarry = false;

	for (unsigned index = 1; index <= num1.length(); ++index)
	{
		char sum = num1[num1.length() - index] - '0' +
			(index <= num2.length() ? num2[num2.length() - index] : '0') + bcarry;

		if (sum>'9')
		{
			num1[num1.length() - index] = sum - 10;
			bcarry = true;
		}
		else
		{
			num1[num1.length() - index] = sum;
			bcarry = false;
		}
	}

	if (bcarry)
	{
		return "1" + num1;
	}
	return num1;
}


// Leetcode 1114	Print in order
class Foo
{
public:
	int							count = 0;
	std::mutex					mtx;
	std::condition_variable		cv;

	Foo()
	{
		count = 1;
		//cv.notify_all();
	}

	void first(std::function<void()> printFirst)
	{
		std::unique_lock<std::mutex>lck(mtx);
		printFirst();
		count = 2;
		lck.unlock();
		cv.notify_all();	//	唤醒所有等待线程
	}

	void second(std::function<void()> printSecond)
	{
		std::unique_lock<std::mutex>lck(mtx);
		cv.wait(lck, [this]() {return count == 2; });

		printSecond();
		count = 3;
		lck.unlock();
		cv.notify_all();
	}

	void third(std::function<void()> printThird)
	{
		std::unique_lock<std::mutex>lck(mtx);
		cv.wait(lck, [this]() {return count == 3; });

		printThird();
	}

};




// Leetcode 1115	Print FooBar Alternately
class FooBar
{
public:
	FooBar(int n) : shouldFoo(true) {
		this->n = n;
	}

	void foo(std::function<void()> printFoo) {
		for (int i = 0; i < n; i++) {
			std::unique_lock<std::mutex> lck(m);
			cv.wait(lck, [this] { return shouldFoo; });
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			shouldFoo = false;
			cv.notify_one();	//	随机唤醒一个等待线程
		}
	}

	void bar(std::function<void()> printBar) {
		for (int i = 0; i < n; i++) {
			std::unique_lock<std::mutex> lck(m);
			cv.wait(lck, [this] { return !shouldFoo; });
			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			shouldFoo = true;
			cv.notify_one();
		}
	}

private:
	int n;
	std::mutex m;
	std::condition_variable cv;
	bool shouldFoo;
};