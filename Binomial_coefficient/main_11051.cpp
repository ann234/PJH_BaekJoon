#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int** memory = new int*[N + 1];
	for (int i = 0; i <= N; i++)
	{
		memory[i] = new int[K + 1];
		memory[i][0] = 1;
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j > i)
				memory[i][j] = 0;
			else
			{
				memory[i][j] = (memory[i - 1][j - 1] + memory[i - 1][j])%10007;
			}
		}
	}

	cout << memory[N][K];
}