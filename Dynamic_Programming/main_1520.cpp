#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dfs(int row, int col, int M, int N, unsigned long long**& memory, int**& data);
int dfs_stack(int row, int col, int M, int N, unsigned long long**& memory, int**& data);

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

	//	memory[i][j] = (i, j)에서 목적지(M - 1, N - 1)으로 갈 수 있는 경우
	unsigned long long** memory = new unsigned long long*[M];
	for (int i = 0; i < M; i++)
	{
		memory[i] = new unsigned long long[N];
		std::fill_n(memory[i], N, -1);
	}

	//cout << dfs(0, 0, M, N, memory, data);
	cout << dfs_stack(0, 0, M, N, memory, data);
}

int dfs(int row, int col, int M, int N, unsigned long long**& memory, int**& data)
{
	int ret = 0;
	if (row == M - 1 && col == N - 1)
		return 1;
	if (memory[row][col] != -1)
		return memory[row][col];

	if (row <= M - 2 && data[row][col] > data[row + 1][col])	//	To Down
	{
		ret += dfs(row + 1, col, M, N, memory, data);
	}
	if (row >= 1 && data[row][col] > data[row - 1][col])	//	To Up
	{
		ret += dfs(row - 1, col, M, N, memory, data);
	}
	if (col <= N - 2 && data[row][col] > data[row][col + 1])	//	To Right
	{
		ret += dfs(row, col + 1, M, N, memory, data);
	}
	if (col >= 1 && data[row][col] > data[row][col - 1])	//	To Left
	{
		ret += dfs(row, col - 1, M, N, memory, data);
	}

	memory[row][col] = ret;
	return ret;
}

int dfs_stack(int row, int col, int M, int N, unsigned long long**& memory, int**& data)
{
	vector<pair<int, int>> stack;
	stack.push_back(make_pair(row, col));

	int ret = 0;
	while (!stack.empty())
	{
		auto p = stack.back();
		stack.pop_back();

		int i = p.first, j = p.second;

		if (i == M - 1 && j == N - 1)
		{
			ret += 1;
			continue;
		}

		if (i <= M - 2 && data[i][j] > data[i + 1][j])	//	To Down
		{
			stack.push_back(make_pair(i + 1, j));
		}
		if (i >= 1 && data[i][j] > data[i - 1][j])	//	To Up
		{
			stack.push_back(make_pair(i - 1, j));
		}
		if (j <= N - 2 && data[i][j] > data[i][j + 1])	//	To Right
		{
			stack.push_back(make_pair(i, j + 1));
		}
		if (j >= 1 && data[i][j] > data[i][j - 1])	//	To Left
		{
			stack.push_back(make_pair(i, j - 1));
		}
	}

	return ret;
}