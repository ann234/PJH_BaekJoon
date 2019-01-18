#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

std::vector<int> counting_sort(std::vector<int> arr, int num_limit);

int main()
{
	int N;
	cin >> N;
	std::vector<int> cumulative_sum(10001, 0);
	//	������ ���
	for (int i = 0, val; i < N; i++)
	{
		scanf_s("%d", &val);
		++cumulative_sum[val];
	}

	for (int i = 0; i < cumulative_sum.size(); i++)
	{
		for (int j = 0; j < cumulative_sum[i]; j++)
		{
			printf("%d\n", i);
		}
	}

	///Sorting
	//auto sorted = counting_sort(arr, 10);
	///
	return 0;
}

//	�޸� �ʰ�(�Է¹��� �� ��ŭ�� �迭�� ������ �ʿ�X)
std::vector<int> counting_sort(std::vector<int> arr, int num_limit)
{
	std::vector<int> cumulative_sum(num_limit, 0);

	//	������ ���
	for (int val : arr)
	{
		++cumulative_sum[val];
	}

	//	���������� ��ȯ
	for (int i = 1; i < cumulative_sum.size(); i++)
	{
		cumulative_sum[i] += cumulative_sum[i - 1];
	}
	
	std::vector<int> ret(arr.size(), 0);
	//	������ �迭 ����Ͽ� ����
	for (int val : arr)
	{
		int idx = (cumulative_sum[val] - 1);
		ret[idx] = val;
		--cumulative_sum[val];
	}

	return ret;
}