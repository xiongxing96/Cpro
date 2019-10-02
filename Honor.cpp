#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

class Solution
{
public:
	int valueofPolynomial(string s)
	{
		int len = s.size();
		int x, num[1000], dex = 0, temp = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				temp = s[i] - '0';
			}
			else if (s[i] == '+')
			{
				temp = 0;
				continue;
			}
			else if (s[i] == '^')
			{
				x = temp;
				continue;
			}
			else
			{
				num[dex++] = temp;
				temp = 0;
			}
		}
		temp = num[0];
		for (int i = 1; i < dex; i++)
		{
			temp = temp * x + num[i];
		}
		return temp;
	}
};

int main()
{
	Solution Plain;
	string str = "4*3^3+5*3^2+6*3^1+7*3^0";
	cout << Plain.valueofPolynomial(str) << endl;
	return 0;
}

