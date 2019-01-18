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
	//	누적값 계산
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

//	메모리 초과(입력받은 수 만큼의 배열을 생성할 필요X)
std::vector<int> counting_sort(std::vector<int> arr, int num_limit)
{
	std::vector<int> cumulative_sum(num_limit, 0);

	//	누적값 계산
	for (int val : arr)
	{
		++cumulative_sum[val];
	}

	//	누적합으로 변환
	for (int i = 1; i < cumulative_sum.size(); i++)
	{
		cumulative_sum[i] += cumulative_sum[i - 1];
	}
	
	std::vector<int> ret(arr.size(), 0);
	//	누적합 배열 사용하여 정렬
	for (int val : arr)
	{
		int idx = (cumulative_sum[val] - 1);
		ret[idx] = val;
		--cumulative_sum[val];
	}

	return ret;
}