#pragma once

#include <iostream>
#include <unordered_map>
#include <string>		//	for the usage of 'to_string'
#include <objbase.h>	//	for the usage of 'CoInitialize'
#include <assert.h>
#include <mutex>		//	for the usage of 'std::mutex' & 'std::unique_lock<>'
#include <functional>	//	for the usage of 'std::function()'
#include <algorithm>	//	for the usage of 'std::for_each()'
#include <queue>		//	for the usage of 'std::queue<>'

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};



class Leet_Solution
{

public:

	int searchInsert(std::vector<int> &nums, int target);

	std::string addString(std::string num1, std::string num2);




protected:

private:
};
