#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	const int MAX_TIME = 100001;
	vector<int> answers;

	int T; cin >> T;
	for (int testcase = 0, N, K, W; testcase < T; testcase++)
	{
		cin >> N >> K;
		vector<int> build_time(N + 1, MAX_TIME);
		for (int i = 1, val; i <= N; i++)
		{
			cin >> val;
			build_time[i] = val;
		}
		vector<vector<int>> graph(N + 1);
		vector<int> required(N + 1, 0);
		required[0] = N;
		for (int i = 0, l, r; i < K; i++)
		{
			cin >> l >> r;
			graph[l].push_back(r);
			required[r] += 1;	//	l�ǹ��� ���µ� �ʿ��� �ǹ��� ��
		}
		cin >> W;

		//	memory[i]: i�ǹ��� ���µ� �ʿ��� �ּҽð�
		int* memory = new int[N + 1];
		for (int i = 0; i <= N; i++)
			memory[i] = 0;


		//	�䱸 �ǹ��� ���� �ǹ��� ���� ť�� �ְ� �ʿ�Ǽ��ð��� �ʱ�ȭ�Ѵ�.
		queue<int> needs_to_build;
		for (int i = 1; i <= N; i++)
			if (required[i] == 0)
			{
				memory[i] = build_time[i];
				needs_to_build.push(i);
			}

		//	ť�� �� �� ����
		while (!needs_to_build.empty())
		{
			//	ť�� �ִ� head �ǹ��� ������
			int head = needs_to_build.front();
			needs_to_build.pop();
			//	head�� �ʿ�� �ϴ� �ǹ����� ���鼭
			for (int nxt : graph[head])
			{
				//	head�� ���µ� �ʿ��� �ð� + nxt���� ���µ� �ʿ��� �ð���
				//	���� nxt�� ���µ� �� �ʿ��� �ð����� ū ��� ��ü
				if (memory[head] + build_time[nxt] > memory[nxt])
				{
					memory[nxt] = memory[head] + build_time[nxt];
				}
				//	nxt�ǹ��� ���µ� �ʿ��� head�� �湮�����Ƿ�, �ʿ�ǹ������� ����
				required[nxt] -= 1;
				//	nxt�ǹ��� ���� ��� �ʿ�ǹ��� �ּ� 1���� �湮���� ���
				if (required[nxt] <= 0)
				{
					//	ť�� �ֱ�
					needs_to_build.push(nxt);
				}
			}
		}

		answers.push_back(memory[W]);

		delete[] memory;
	}

	for (int val : answers)
		cout << val << endl;
}