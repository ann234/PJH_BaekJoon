#include <iostream>
#include <vector>

using namespace std;

int main()
{
	const int DIVIDE = 1000000000;
	int N;	cin >> N;

	//	memory[i][j]: i번째 자리에 j가 있는 숫자의 계단수 개수
	int** memory = new int*[N + 1];
	for (int i = 1; i <= N; i++)
	{
		memory[i] = new int[10];
		for (int j = 0; j < 10; j++)
			memory[i][j] = 0;
	}

	memory[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		memory[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j >= 1)
				memory[i][j] += memory[i - 1][j - 1];
			if (j <= 8)
				memory[i][j] += memory[i - 1][j + 1];
			memory[i][j] %= DIVIDE;
		}
	}

	int ret = 0;
	for (int i = 0; i < 10; i++)
	{
		ret += memory[N][i];
		ret %=DIVIDE;
	}

	cout << ret << endl;
}