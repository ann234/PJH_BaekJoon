#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum ECODE
{
	p2, m2, p3, m3
};

int main()
{
	string str;
	cin >> str;

	bool is_valid = true;
	std::vector<char> stack;
	std::vector<ECODE> stack_ret;
	int ret = 0;
	int sub_ret = 0;
	bool is_stacked = false;
	for (int j = str.length(); j >= 0; j--)
	{
		switch (str[j])
		{
		case '(':
			if (str[j + 1] == ')')
			{
				if (!is_stacked)
					stack_ret.push_back(p2);
				else
					stack_ret.push_back(m2);
			}
			break;
		case '[':
			break;
		case ')':
			stack.push_back(')');
			is_stacked = false;
			break;
		case ']':
			stack.push_back(']');
			is_stacked = false;
			break;
		}
	}
	if (stack.size() > 0)
		is_valid = false;
}