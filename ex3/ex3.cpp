#include "ex3.h"
using std::vector;
int ex3::factor_print(const size_t& number)
{
	factor_dc(number);
	return 0;
}

size_t ex3::factor_dc(const size_t& n)
{
	if (n == 1)//������Ϊ1�������Ѿ��ֽ⵽���һ�����ӣ�����1��ʾһ��������
		return 1;
	size_t count(0);
	for (size_t i = 2; i <= n; i++)
		if (n % i == 0)
			count += factor_dc(n / i);
	return count;
}

size_t ex3::factor_dp(const size_t& n)
{
	//�����1��sqrt(n)���������ӵĸ���
	vector<size_t> factor;
	for (size_t i = 1; i <= sqrt(n); i++)
		if (n % i == 0)
			factor.push_back(i);

	/*
	* �����ƽ���������ж�������
	*/
	long long i = factor.size() - 1;
	if (factor[i] * factor[i] == n)
		i--;
	//�����sqrt(n)��n���������ӵĸ���
	for (; i != -1; --i)
		factor.push_back(n / factor[i]);
	//���ڣ�factorΪ���е�����
	//����������ʼ����̬�滮���飺dp
	vector<size_t> dp(factor.size(), 0);
	//��ʼ��dp[0]����1����������Ϊ1
	dp[0] = 1;
	//��ʼ��̬�滮���̣�����1<i<���������ķ�Χ�ڣ��ж�j������iС�������Ƿ���i������������ǣ�������dp[j]ȥ����dp[i];
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





