#include <iostream>
#include <vector>

using namespace std;

int main()
{
	unsigned long long int n;
	cin >> n;

	const int DIVIDE = 1000000LL;
	//	피사노 주기를 통해 시간복잡도 낮추기
	const int p = DIVIDE / 10 * 15;
	int answer;

	int* memory = new int[p];
	memory[0] = 0;	memory[1] = 1;
	for (int i = 2; i <= p; i++)
	{
		memory[i] = memory[i - 1] + memory[i - 2];
		memory[i] %= DIVIDE;
	}

	cout << memory[n%p];
}