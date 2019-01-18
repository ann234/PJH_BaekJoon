#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	queue<int> q;
	vector<int> answer;
	for (int i = 1; i <= N; i++)
		q.push(i);

	int cnt = 0;
	while (!q.empty())
	{
		int head = q.front();
		q.pop();	cnt++;
		if (cnt % M != 0)
			q.push(head);
		else
		{
			answer.push_back(head);
			cnt = 0;
		}
	}

	cout << '<';
	for (int i = 0; i < answer.size() - 1; i++)
		cout << answer[i] << ", ";
	cout << answer[answer.size() - 1] << '>';
}