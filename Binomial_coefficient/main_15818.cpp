#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	unsigned long long M;
	cin >> N >> M;

	unsigned long long answer = 1;
	for (unsigned long long i = 0, val; i < N; i++)
	{
		cin >> val;
		answer = ((answer%M)*(val%M)) % M;
	}

	cout << answer;
}