#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<pair<int, int>> answers;

	int T;	cin >> T;
	for (int testcase = 0; testcase < T; testcase++)
	{
		int N;	cin >> N;

		vector<pair<int, pair<int, int>>> memory(N + 1);
		int cnt0 = 0, cnt1 = 0;

		for (int n = 0; n <= N; n++)
		{
			if (n == 0) {
				memory[n] = make_pair(0, make_pair(1, 0));
			}
			else if (n == 1) {
				memory[n] = make_pair(1, make_pair(0, 1));
			}
			else {
				int val = memory[n - 1].first + memory[n - 2].first;
				int cnt0 = memory[n - 1].second.first + memory[n - 2].second.first;
				int cnt1 = memory[n - 1].second.second + memory[n - 2].second.second;
				memory[n] = make_pair(val, make_pair(cnt0, cnt1));
			}
		}

		answers.push_back(make_pair(memory[N].second.first, memory[N].second.second));
	}

	for (auto val : answers)
	{
		cout << val.first << ' ' << val.second << endl;
	}
}