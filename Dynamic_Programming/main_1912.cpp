#include <iostream>
#include <vector>

using namespace std;

//	[R][C]: R ���ڿ��� �����ؼ� C���� ������ ���� ��
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
	//	N�� �������� �� ���� ū ��
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