#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	std::vector<int> arr(N, 0);
	for (int i = 0, val; i < N; i++)
	{
		cin >> val;
		arr[i] = val;
	}

	std::vector<int> stack;
	std::vector<bool> stack_order;

	bool is_possible = true;
	int pin = 0;
	int val = 1;
	while (true)
	{
		//	������ ���� ��� Ż��
		if (pin >= arr.size())
			break;
		//	���� ���� ���� ���� ���� �ʿ��� ������ ���� ���
		if (stack.size() > 0 && stack[stack.size() - 1] == arr[pin])
		{
			//	Pop(-)
			stack.pop_back();
			stack_order.push_back(true);
			pin += 1;
		}
		else
		{
			//	���ÿ� �� �߰�
			stack.push_back(val++);
			//	Push(+)
			stack_order.push_back(false);
			//	������ ���� ���� ���� ���� �ʿ��� ������ ������ ū ���
			//	���� ������ ���� �� ����
			if (stack[stack.size() - 1] > arr[pin])
			{
				//	WRONG!
				is_possible = false;
				break;
			}
		}
	}

	if (is_possible)
	{
		for (int i = 0; i < stack_order.size(); i++)
		{
			if (stack_order[i])
				printf("%c\n", '-');
			else
				printf("%c\n", '+');
		}
	}
	else
	{
		printf("NO");
	}

	return 0;
}