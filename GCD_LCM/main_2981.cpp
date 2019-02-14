#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;	cin >> N;
	vector<int> data;
	for (int i = 0, val; i < N; i++)
	{
		cin >> val;
		data.push_back(val);
	}
	sort(data.begin(), data.end());
	int second = data[1];

	vector<int> answers;
	int cnt = N;
	for (int i = 2; i <= second; i++)
	{
		int prev = data[0] % i;
		for (int val : data)
		{
			if ((val % i) != prev)
				break;
			else
				cnt -= 1;
		}

		if (cnt == 0)
			answers.push_back(i);
		cnt = N;
	}

	for (int answer : answers)
		cout << answer << " ";
}