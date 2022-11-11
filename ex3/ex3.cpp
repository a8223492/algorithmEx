#include "ex3.h"
using std::vector;
int ex3::factor_print(const size_t& number)
{
	factor_dc(number);
	return 0;
}

size_t ex3::factor_dc(const size_t& n)
{
	if (n == 1)//当参数为1，代表已经分解到最后一个因子，返回1表示一个因数。
		return 1;
	size_t count(0);
	for (size_t i = 2; i <= n; i++)
		if (n % i == 0)
			count += factor_dc(n / i);
	return count;
}

size_t ex3::factor_dp(const size_t& n)
{
	//先求出1到sqrt(n)的所有因子的个数
	vector<size_t> factor;
	for (size_t i = 1; i <= sqrt(n); i++)
		if (n % i == 0)
			factor.push_back(i);

	/*
	* 如果是平方数，加判断条件吧
	*/
	long long i = factor.size() - 1;
	if (factor[i] * factor[i] == n)
		i--;
	//再求出sqrt(n)到n的所有因子的个数
	for (; i != -1; --i)
		factor.push_back(n / factor[i]);
	//现在，factor为所有的因数
	//接下来，初始化动态规划数组：dp
	vector<size_t> dp(factor.size(), 0);
	//初始化dp[0]，即1的因数个数为1
	dp[0] = 1;
	//开始动态规划过程，即在1<i<因数个数的范围内，判断j，即比i小的因数是否是i的因数，如果是，则利用dp[j]去增加dp[i];
	for (size_t i = 1; i < factor.size(); i++)
		for (size_t j = 0; j < i; j++)
			if (factor[i] % factor[j] == 0)
				dp[i] += dp[j];
	return dp.back();
}

int ex3::max_sub_array(const vector<int>& arr)
{
	const auto count = arr.size();
	auto dp_0 = arr[0];
	auto dp_1 = dp_0;
	auto max = 0;
	
	for (size_t i = 1; i < count; i++)
	{
		dp_1 = std::max(dp_0 + arr[i], dp_0);
		dp_0 = dp_1;
		max = std::max(dp_1, max);
	}
	return max;
	

}





