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
			required[r] += 1;	//	l건물을 짓는데 필요한 건물의 수
		}
		cin >> W;

		//	memory[i]: i건물을 짓는데 필요한 최소시간
		int* memory = new int[N + 1];
		for (int i = 0; i <= N; i++)
			memory[i] = 0;


		//	요구 건물이 없는 건물을 먼저 큐에 넣고 필요건설시간을 초기화한다.
		queue<int> needs_to_build;
		for (int i = 1; i <= N; i++)
			if (required[i] == 0)
			{
				memory[i] = build_time[i];
				needs_to_build.push(i);
			}

		//	큐가 빌 때 까지
		while (!needs_to_build.empty())
		{
			//	큐에 있는 head 건물을 빼낸다
			int head = needs_to_build.front();
			needs_to_build.pop();
			//	head를 필요로 하는 건물들을 돌면서
			for (int nxt : graph[head])
			{
				//	head를 짓는데 필요한 시간 + nxt만을 짓는데 필요한 시간이
				//	현재 nxt를 짓는데 총 필요한 시간보다 큰 경우 교체
				if (memory[head] + build_time[nxt] > memory[nxt])
				{
					memory[nxt] = memory[head] + build_time[nxt];
				}
				//	nxt건물을 짓는데 필요한 head를 방문했으므로, 필요건물갯수를 감소
				required[nxt] -= 1;
				//	nxt건물을 위한 모든 필요건물을 최소 1번씩 방문했을 경우
				if (required[nxt] <= 0)
				{
					//	큐에 넣기
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