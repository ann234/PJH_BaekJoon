#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	int N;	cin >> N;
	vector<int> points(N + 1);
	for (int i = 1, val; i <= N; i++)
	{
		cin >> val;
		points[i] = val;
	}

	//	step continuity, point
	//	�� ����� ���¿��� ���� �� �ִ� �ִ� �������� ����
	int** memory = new int*[N + 1];
	for (int i = 0; i <= N; i++)
		memory[i] = new int[3];

	//	memory[i][j]: j�� �������� ����� �ö� i�� �������� �� �ִ�����
	memory[0][1] = 0;	memory[0][2] = 0;
	memory[1][1] = points[1];	memory[1][2] = 0;
	for (int i = 2; i <= N; i++)
	{
		memory[i][1] = max(memory[i - 2][1], memory[i - 2][2]) + points[i];
		memory[i][2] = memory[i - 1][1] + points[i];
	}

	cout << max(memory[N][1], memory[N][2]) << endl;
}
