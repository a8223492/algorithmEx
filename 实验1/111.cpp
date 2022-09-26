#include <iostream>
 
using namespace std;
 
int num[3] = { 8,0,0 };//水壶内水量的当前状态
int maxx[3] = { 8,5,3 };//水壶容量
int p[200][3];//水壶的水量状态保存
int i = 0;//模拟倒水次数
bool can(int from, int to)//判断是否可以从from水壶中倒水到to水壶中
{
	if (num[from] == 0)
	{
		return false;
	}
 
	if (num[to] == maxx[to])
	{
		return false;
	}
	else
	{
		return true;
	}
}
void pour(int from, int to)//倒水过程
{
	if (num[from] + num[to] > maxx[to])
	{
		num[from] = num[from] - (maxx[to] - num[to]);
		num[to] = maxx[to];
	}
	else
	{
		num[to] = num[to] + num[from];
		num[from] = 0;
	}
}
bool panduan(int f, int t, int l)//判断倒水之后水壶状态与之前的是否重复
{
	for (int m = 0;m <= i;m++)
	{
		if (f == p[m][0] && t == p[m][1] && l == p[m][2])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cout << num[0] << num[1] << num[2] << endl;
	while (num[0] != 4 && num[1] != 4 && num[2] != 4)
	{
		if (can(0, 1)) 
		{
			p[i][0] = num[0];//保存当前水壶状态
			p[i][1] = num[1];
			p[i][2] = num[2];
			i++;
			pour(0, 1);
			if (!panduan(num[0], num[1], num[2]))
			{//撤销倒水操作
				num[0] = p[i - 1][0];
				num[1] = p[i - 1][1];
				num[2] = p[i - 1][2];
			}
			else
			cout << num[0] << num[1] << num[2] << endl;
			
		}
		if (can(0, 2) )
		{
			p[i][0] = num[0];
			p[i][1] = num[1];
			p[i][2] = num[2];
			i++;
			pour(0, 2);
			if (!panduan(num[0], num[1], num[2]))
			{
				num[0] = p[i - 1][0];
				num[1] = p[i - 1][1];
				num[2] = p[i - 1][2];
			}
			else
			cout << num[0] << num[1] << num[2] << endl;
			
		}
		if (can(1, 0))
		{
			p[i][0] = num[0];
			p[i][1] = num[1];
			p[i][2] = num[2];
			i++;
			pour(1, 0);
			if (!panduan(num[0], num[1], num[2]))
			{
				num[0] = p[i - 1][0];
				num[1] = p[i - 1][1];
				num[2] = p[i - 1][2];
			}
			else
			cout << num[0] << num[1] << num[2] << endl;
			
		}
		if (can(2, 0) )
		{
			p[i][0] = num[0];
			p[i][1] = num[1];
			p[i][2] = num[2];
			i++;
			pour(2, 0);
			if (!panduan(num[0], num[1], num[2]))
			{
				num[0] = p[i-1][0];
				num[1] = p[i - 1][1];
				num[2] = p[i - 1][2];
			}
			else
			cout << num[0] << num[1] << num[2] << endl;
			
		}
		if (can(2, 1) )
		{
			p[i][0] = num[0];
			p[i][1] = num[1];
			p[i][2] = num[2];
			i++;
			pour(2, 1);
			if (!panduan(num[0], num[1], num[2]))
			{
				num[0] = p[i - 1][0];
				num[1] = p[i - 1][1];
				num[2] = p[i - 1][2];
			}
			else
			cout << num[0] << num[1] << num[2] << endl;
			
		}
		if (can(1, 2) )
		{
			p[i][0] = num[0];
			p[i][1] = num[1];
			p[i][2] = num[2];
			i++;
			pour(1, 2);
			if (!panduan(num[0], num[1], num[2]))
			{
				num[0] = p[i - 1][0];
				num[1] = p[i - 1][1];
				num[2] = p[i - 1][2];
			}
			else
			cout << num[0] << num[1] << num[2] << endl;
			
		}
		
	}
}
