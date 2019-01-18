#include <iostream>
#include <vector>

using namespace std;

int main()
{
	const int MAX_VAL = 1000000;
	int N;	cin >> N;

	//	memory[i] = 정수 N에서 i까지 도달하는데 필요한 최소 연산 횟수
	int* memory = new int[N + 1];
	for (int i = 0; i < N; i++)
	{
		memory[i] = MAX_VAL;
	}
	memory[N] = 0;

	for (int i = N; i >= 1; i--)
	{
		int cal = memory[i];
		if (i % 3 == 0)
		{
			if (memory[i / 3] > cal + 1)
				memory[i / 3] = cal + 1;
		}
		if (i % 2 == 0)
		{
			if (memory[i / 2] > cal + 1)
				memory[i / 2] = cal + 1;
		}
		if (memory[i - 1] > cal + 1)
			memory[i - 1] = cal + 1;
	}

	cout << memory[1] << endl;
}