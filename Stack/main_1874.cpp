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
		//	수열을 만든 경우 탈출
		if (pin >= arr.size())
			break;
		//	스택 가장 위의 값이 현재 필요한 수열의 값인 경우
		if (stack.size() > 0 && stack[stack.size() - 1] == arr[pin])
		{
			//	Pop(-)
			stack.pop_back();
			stack_order.push_back(true);
			pin += 1;
		}
		else
		{
			//	스택에 값 추가
			stack.push_back(val++);
			//	Push(+)
			stack_order.push_back(false);
			//	스택의 가장 위의 값이 현재 필요한 수열의 값보다 큰 경우
			//	절대 수열을 만들 수 없다
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