#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<int> answers;
	for (int i = 0; i < T; i++)
	{
		int N, M;
		cin >> N >> M;

		//	index, priority
		queue<pair<int, int>> q;
		vector<int> val_order;
		for (int j = 0, val; j < N; j++)
		{
			cin >> val;
			val_order.push_back(val);
			q.push(make_pair(j, val));
		}
		//	�߿䵵�� ������������
		sort(val_order.begin(), val_order.end());

		int cnt = 0;
		while (!q.empty())
		{
			auto val = q.front();
			//	���� ���� �߿䵵��
			int max_val = val_order[val_order.size() - 1];
			//	Queue�� head�� ���� ���� �߿䵵������ ���� ���
			if (val.second < max_val)
			{
				//	�� �ڷ� ����
				q.pop();
				q.push(val);
			}
			else
			{
				q.pop();
				cnt++;
				if (val.first == M)
				{
					answers.push_back(cnt);
					break;
				}
				val_order.pop_back();
			}
		}
	}

	for (int val : answers)
		cout << val << endl;
}