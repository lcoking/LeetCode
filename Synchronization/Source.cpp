#include "Header.h"

int raii_template_test()
{
	for (int i = 0; i< 1e4;++i)
	{
		auto arp = auto_release_ptr<int64_t>(new int64_t[3]);
		int64_t* ptr = arp.getPtr();

		ptr[0] = 1;
		ptr[1] = 2;
		ptr[2] = 3;
	}

	system("pause");
	return 0;
}


int auto_ptr_doodle()
{
	
	std::auto_ptr<double> apd(new double(9.13));
	std::cout << "*apd = " << *apd << std::endl;
	std::cout << "apd.get() = " << reinterpret_cast<long>(apd.get()) << std::endl;


	double* pd = new double(7.77);
	std::auto_ptr<double> apd2(pd);
	std::cout << "pd = " << reinterpret_cast<long>(pd) << std::endl;
	std::cout << "apd.get() = " << reinterpret_cast<long>(apd2.get()) << std::endl;


	return 0;
}



int main()
{
	//raii_template_test();
	auto_ptr_doodle();
	return 0;
}