#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int M, N;	cin >> M >> N;

	int** data = new int*[M];
	for (int i = 0; i < M; i++)
	{
		data[i] = new int[N];
		for (int j = 0, val; j < N; j++)
		{
			cin >> val;
			data[i][j] = val;
		}
	}

	//	memory[i][j] = 시작점(0, 0)에서 (i, j)칸으로 갈 수 있는 경우의 수
	unsigned long long** memory = new unsigned long long*[M];
	for (int i = 0; i < M; i++)
	{
		memory[i] = new unsigned long long[N];
		std::fill_n(memory[i], N, 0);
	}
	/*bool** checked = new bool*[M];
	for (int i = 0; i < M; i++)
	{
		checked[i] = new bool[N];
		std::fill_n(checked[i], N, false);
	}*/
	int** checked = new int*[M];
	for (int i = 0; i < M; i++)
	{
		checked[i] = new int[N];
		std::fill_n(checked[i], N, 0);
		for (int j = 0; j < N; j++)
		{
			if (j <= N - 2 && data[i][j] < data[i][j + 1])	//	From right
			{
				checked[i][j] += 1;
			}
			if (i <= M - 2 && data[i][j] < data[i + 1][j])	//	From Down
			{
				checked[i][j] += 1;
			}
			if (j >= 1 && data[i][j - 1] > data[i][j])		//	From left
			{
				checked[i][j] += 1;
			}
			if (i >= 1 && data[i - 1][j] > data[i][j])		//	From Up
			{
				checked[i][j] += 1;
			}
		}
	}

	memory[0][0] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 1));
	q.push(make_pair(1, 0));
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		int i = p.first, j = p.second;

		if (j <= N - 2 && data[i][j] < data[i][j + 1])	//	From right
		{
			memory[i][j] += memory[i][j + 1];
			checked[i][j] -= 1;
		}
		if (i <= M - 2 && data[i][j] < data[i + 1][j])	//	From Down
		{
			memory[i][j] += memory[i + 1][j];
			checked[i][j] -= 1;
		}
		if (j >= 1 && data[i][j - 1] > data[i][j])	//	From left
		{
			memory[i][j] += memory[i][j - 1];
			checked[i][j] -= 1;
		}
		if (i >= 1 && data[i - 1][j] > data[i][j])	//	From Up
		{
			memory[i][j] += memory[i - 1][j];
			checked[i][j] -= 1;
		}

		if (checked[i][i] <= 0)
			q.push(make_pair(i, j));
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << memory[i][j];
		cout << endl;
	}

	cout << memory[M - 1][N - 1];
}