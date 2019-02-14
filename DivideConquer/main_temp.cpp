#include <iostream>
#include <vector>
#include <deque>
#include <time.h>

using namespace std;


template<class T>
void swap(vector<T>& data, int left, int right);
int partition(vector<int64_t>& data, int left, int right, int pivot);
void _quicksort(vector<int64_t>& data, int left, int right);
void quicksort(vector<int64_t>& data, int left, int right);

int K;

int main()
{
	int N;
	vector<int64_t> arr;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int64_t val;
		scanf_s("%l64d", &val);
		arr.push_back(val);
	}

	srand((unsigned int)time(0));
	_quicksort(arr, 0, arr.size() - 1);

	cout << arr[K - 1];
}

//int main()
//{
//	vector<int64_t> arr;
//
//	srand((unsigned int)time(0));
//	for (int i = 0; i < 20; i++)
//	{
//		int val = rand() % 100;
//		arr.push_back(val);
//	}
//
//	srand((unsigned int)time(0));
//	_quicksort(arr, 0, arr.size() - 1);
//	for (unsigned int val : arr)
//		cout << val << " ";
//}

template<class T>
void swap(vector<T>& data, int left, int right)
{
	T temp = data[left];
	data[left] = data[right];
	data[right] = temp;
}

int partition(vector<int64_t>& data, int left, int right, int pivot)
{
	int64_t pivotValue = data[pivot];
	swap(data, right, pivot);

	int curr_idx = left;
	for (int i = left; i <= right - 1; i++)
	{
		if (data[i] < pivotValue || data[i] == pivotValue)
		{
			swap(data, i, curr_idx);
			curr_idx += 1;
		}
	}

	swap(data, curr_idx, right);
	return curr_idx;
}

void _quicksort(vector<int64_t>& data, int left, int right)
{
	if (right > left)
	{
		int pivot = (rand() % (right - left + 1)) + left;
		int new_pivot_idx = partition(data, left, right, pivot);
		_quicksort(data, left, new_pivot_idx - 1);
		_quicksort(data, new_pivot_idx + 1, right);
	}
}

void quicksort(vector<int64_t>& data, int left, int right)
{
	if (right > left)
	{
		srand((unsigned int)time(0));
		int pivot = (rand() % (right - left + 1)) + left;
		int new_pivot_idx = partition(data, left, right, pivot);
		if (new_pivot_idx == K - 1)
			return;
		else if (new_pivot_idx > K - 1)
			quicksort(data, left, new_pivot_idx - 1);
		else
			quicksort(data, new_pivot_idx + 1, right);
	}
}