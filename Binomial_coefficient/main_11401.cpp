#include <iostream>
#include <vector>

using namespace std;

long long mul(long long x, long long y, long long p) {
	long long ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}

int main()
{
	constexpr unsigned long long DIVIDE{ 1000000007 };
	int N, K;
	cin >> N >> K;

	unsigned long long den = 1, num1 = 1;
	//	Denominator = (N! % DIVIDE) = (N % DIVIDE) * ((N-1) % DIVIDE) = ...
	for (int i = 1; i <= N; i++)
	{
		den *= i;	den %= DIVIDE;
	}
	//	Numerator K!
	for (int i = 1; i <= K; i++)
	{
		num1 *= i;
		num1 %= DIVIDE;
		//num1 = (num1 % DIVIDE) * (i % DIVIDE);
	}
	//	Numerator (N - K)!
	for (int i = 1; i <= (N - K); i++)
	{
		num1 *= i;
		num1 %= DIVIDE;
		//num1 = (num1 % DIVIDE) * (i % DIVIDE);
	}
	num1 = mul(num1, DIVIDE - 2, DIVIDE);

	/*cout << den << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << den / (num1*num2) << endl;*/

	cout << (den * num1)%DIVIDE << endl;
}