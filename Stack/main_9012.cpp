#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	std::vector<bool> answer;
	for (int i = 0; i < T; i++)
	{
		string str;
		cin >> str;

		bool is_valid = true;
		std::vector<bool> stack;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '(')
			{
				stack.push_back(true);
			}
			else if (str[j] == ')')
			{
				if (stack.size() <= 0)
				{
					//	FAILED
					is_valid = false;
					break;
				}
				else
					stack.pop_back();
			}
		}
		if (stack.size() > 0)
			is_valid = false;

		answer.push_back(is_valid);
	}

	for (bool val : answer)
	{
		if (val)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}