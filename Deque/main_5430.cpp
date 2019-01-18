#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<vector<int>> answers;
	for (int testcase = 0; testcase < T; testcase++)
	{
		string P;
		cin >> P;
		int N;
		cin >> N;

		string arr_str;
		cin >> arr_str;
		string num;
		deque<int> arr;
		for (char c : arr_str)
		{
			if (c >= (int)'0' && c <= (int)'9')
			{
				num.push_back(c);
			}
			else if (num.length() > 0)
			{
				arr.push_back(atoi(num.c_str()));
				num.clear();
			}
		}

		bool is_error = false;
		bool rotate_dir = true;
		for (char c : P)
		{
			switch (c)
			{
			case 'R':
				rotate_dir = !rotate_dir;
				break;
			case 'D':
				if (arr.empty())
				{
					is_error = true;
					break;
				}
				if (rotate_dir)
					arr.pop_front();
				else
					arr.pop_back();
				break;
			}
		}

		vector<int> answer;
		if (is_error)
			answer.push_back(-1);
		else if (arr.size() > 0)
		{
			if (rotate_dir)
				for (int i = 0; i < arr.size(); i++)
					answer.push_back(arr[i]);
			else
				for (int i = arr.size() - 1; i >= 0; i--)
					answer.push_back(arr[i]);
		}

		answers.push_back(answer);
	}

	for (vector<int> answer : answers)
	{
		if (answer.size() > 0 && answer[0] == -1)
		{
			cout << "error" << endl;
			continue;
		}
		cout << '[';
		if (answer.size() > 0)
		{
			for (int i = 0; i < answer.size() - 1; i++)
				cout << answer[i] << ',';
			cout << answer[answer.size() - 1];
		}
		cout << ']' << endl;
	}
}