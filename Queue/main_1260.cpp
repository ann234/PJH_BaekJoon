#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//	내림차순
bool desc(int a, int b)
{
	return a > b;
}

vector<int> DFS(const vector<vector<int>>& graph, const int start_node)
{
	int N = graph.size();
	std::vector<bool> checked(N, false);
	std::vector<int> stack;
	std::vector<int> order;
	order.push_back(start_node);

	checked[start_node] = true;
	for (int i = 0; i < graph[start_node].size(); i++)
	{
		stack.push_back(graph[start_node][i]);
	}
	sort(stack.begin(), stack.end(), desc);

	while (!stack.empty())
	{
		int pop = stack[stack.size() - 1];
		stack.pop_back();
		if (checked[pop])
			continue;

		checked[pop] = true;
		order.push_back(pop);

		std::vector<int> unordered;
		for (int i = 0; i < graph[pop].size(); i++)
		{
			//if (!checked[graph[pop][i]])
			{
				unordered.push_back(graph[pop][i]);
			}
		}
		sort(unordered.begin(), unordered.end(), desc);
		for (int val : unordered)
		{
			stack.push_back(val);
		}
	}

	return order;
}

//void BFS_TEMP(int v, int N) {
//	queue<int> q;            //bfs에서는 q를사용
//	q.push(v);
//	visited[v] = true;            //방문한 노드를 visit 1에서 0으로 변경
//	while (!q.empty()) {
//		v = q.front();
//		cout << q.front() << ' ';
//		q.pop();
//		for (int i = 1; i <= N; i++) {
//			if (visited[i] || !graph_matrix[v][i])
//				continue;
//			q.push(i);
//			visited[i] = true;
//		}
//	}
//}

vector<int> BFS(const vector<vector<int>>& graph, const int start_node)
{
	int N = graph.size();
	std::vector<bool> checked(N, false);
	std::queue<int> q;
	std::vector<int> order;
	q.push(start_node);
	checked[start_node] = true;

	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		order.push_back(p);

		std::vector<int> unordered;
		for (int i = 0; i < graph[p].size(); i++)
		{
			if (!checked[graph[p][i]])
				unordered.push_back(graph[p][i]);
		}
		sort(unordered.begin(), unordered.end());
		for (int val : unordered)
		{
			q.push(val);
			checked[val] = true;
		}
	}

	return order;
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	vector<vector<int>> graph(N + 1);
	for (int i = 0, l, r; i < M; i++)
	{
		cin >> l >> r;
		graph[l].push_back(r);
		graph[r].push_back(l);
	}

	std::vector<int> dfs = DFS(graph, V);
	for (int val : dfs)
		cout << val << ' ';
	cout << endl;

	/*std::vector<int> bfs = BFS(graph, V);
	for (int val : bfs)
		cout << val << ' ';*/
}