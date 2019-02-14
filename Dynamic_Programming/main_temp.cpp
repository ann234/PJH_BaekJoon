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

	/*memory = new int*[N];
	for (int i = 0; i < N; i++)
	{
		memory[i] = new int[N];
		memory[0][0] = arr[0];
		for (int j = 0; j < N; j++)
		{
			memory[0][i] = memory[0][i - 1] + arr[i];
		}
	}*/

	//	0���� N���� ���� ��
	int* mem = new int[N];
	mem[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		mem[i] = mem[i - 1] + arr[i];
	}

	//	N�� �������� �� ���� ū ��


	//int answer = memory[0][0];
	int answer = mem[0];
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			//	memory[i][j] = 0��°���� j��°������ �� - 0��°���� i���������� ��
			int temp = mem[j] - mem[i - 1];
			if (temp > answer)
				answer = temp;
		}
	}

	cout << answer << endl;
}