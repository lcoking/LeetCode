#include "Header.h"


int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();


int Leet_Solution::searchInsert(std::vector<int> &nums, int target)
{
	int bottom = 0;
	int top = nums.size() - 1;

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
		swap(num1, num2);	//½»»»ÄÚÈÝ
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
