#include <iostream>
#include <vector>

using namespace std;

//	[R][C]: R 숫자에서 시작해서 C까지 합했을 때의 값
int** memory;

int main()
{
	int N;
	vector<int> arr;
	cin >> N;
	for (int i = 0, val; i < N; i++)
	{
		scanf_s("%d", &val);
		arr.push_back(val);
	}

	int* mem = new int[N];
	//	N을 포함했을 때 가장 큰 값
	mem[N - 1] = arr[N - 1];
	int a = mem[N - 1];
	for (int i = N - 2; i >= 0; i--)
	{
		mem[i] = arr[i];
		if (mem[i + 1] > 0)
			mem[i] += mem[i + 1];
		if (mem[i] > a)
			a = mem[i];
	}

	cout << a;
}