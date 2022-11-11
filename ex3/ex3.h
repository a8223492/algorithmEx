#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
using std::vector;
class ex3
{
public:
	static int factor_print(const size_t& number);
	static size_t factor_dc(const size_t& n);
	static size_t factor_dp(const size_t& n);
	static int max_sub_array(const vector<int>& arr);
};

