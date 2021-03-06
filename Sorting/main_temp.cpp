#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

std::vector<int> counting_sort(std::vector<int> arr, int num_limit);

int main()
{
	int N;
	cin >> N;
	std::vector<int> cumulative_sum(8001, 0);
	int sum = 0;
	int min = 4001, max = -4001;
	//	누적값 계산
	for (int i = 0, val; i < N; i++)
	{
		scanf_s("%d", &val);
		if (val >= 0)
			++cumulative_sum[val];
		else
			++cumulative_sum[4000 - val];
		if (val < min)
			min = val;
		if (val > max)
			max = val;
		sum += val;	//	산술평균 위한 합도 미리 계산
	}
	//	범위 계산
	int range = (max - min);
	//	산술평균 계산
	int avg = (int)(floor(((float)sum / (float)N) + 0.5));

	//	최빈값 계산
	std::vector<pair<int, int>> mode;
	int cnt = 1;
	for (int i = 0; i < cumulative_sum.size(); i++)
	{
		if (cumulative_sum[i] >= cnt)
		{
			int val;
			if (i <= 4000)
				val = i;
			else
				val = (4000 - i);
			cnt = cumulative_sum[i];
			mode.push_back(make_pair(cnt, val));
		}
	}

	//	누적합으로 변환하면서 중앙값 계산
	const int mid = (N / 2) + 1;
	int closest = N, median;
	for (int i = cumulative_sum.size() - 1; i > 4001; i--)
	{
		cumulative_sum[i - 1] += cumulative_sum[i];
		if (cumulative_sum[i - 1] - cumulative_sum[i] == 0)
			continue;
		if (cumulative_sum[i] < mid
			&& mid <= cumulative_sum[i - 1])
			median = (4000 - (i - 1));
	}
	cumulative_sum[0] += cumulative_sum[4001];
	if (cumulative_sum[0] - cumulative_sum[4001] != 0
		&& cumulative_sum[4001] <= mid
		&& mid <= cumulative_sum[0])
		median = 0;
	for (int i = 1; i <= 4000; i++)
	{
		cumulative_sum[i] += cumulative_sum[i - 1];
		if (cumulative_sum[i] - cumulative_sum[i - 1] == 0)
			continue;
		if (cumulative_sum[i - 1] < mid
			&& mid <= cumulative_sum[i])
			median = i;
	}

	cout << avg << endl;
	cout << median << endl;
	sort(mode.begin(), mode.end());
	std::vector<int> same;
	same.push_back(mode[0].second);
	for (int i = 1; i < mode.size(); i++)
	{
		if (mode[i].first == mode[i - 1].first)
		{
			same.push_back(mode[i].second);
		}
		else
			break;
	}
	if (same.size() >= 2)
	{
		sort(same.begin(), same.end());
		cout << same[1] << endl;
	}
	else
		cout << same[0] << endl;
	cout << range << endl;

	return 0;
}