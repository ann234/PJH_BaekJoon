#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:

public:
	inline SegmentTree(vector<unsigned long int> arr)
		: arr(arr)
	{
		//	�ʿ��� Tree ũ�� = 2^(�ø�(log2(data size)) + 1)
		tree = vector<unsigned long int>(pow(2, ceil(log2(arr.size())) + 1) + 1);
		init(0, arr.size() - 1, 1);
	}

	inline int init(int left, int right, int node)
	{
		//	���� �ϳ��� ���� ���
		if (left == right)	return tree[node] = left;

		int mid = (left + right) >> 1;
		//int mid = (left + right) / 2;
		int leftMinIndex = init(left, mid, node << 1);
		int rightMinIndex = init(mid + 1, right, (node << 1) + 1);

		//	���� �ڽİ� ������ �ڽ� ��� �� ���� ���̸� ���� ���� �����Ͽ� �װ��� 'index'�� ����
		return tree[node] = arr[leftMinIndex] < arr[rightMinIndex] ? leftMinIndex : rightMinIndex;
	}

	vector<unsigned long int> arr;
	vector<unsigned long int> tree;
};

//int calculate_minIdx(SegmentTree& st, int left, int right, int nodeLeft, int nodeRight)
//{
//
//}
//
//int getMaxArea(SegmentTree& st, int left, int right, int nodeLeft, int nodeRight, int least_idx)
//{
//	unsigned long int area = (left - right + 1) * st.arr[least_idx];
//
//	//	���� ��� ����
//	if (least_idx - 1 >= left)
//	{
//		int left_minIdx = calculate_minIdx(st, left, least_idx - 1);
//	}
//
//	//	���� ��� ����
//	if (least_idx + 1 <= right)
//	{
//
//	}
//
//	int left_minIdx = calculate_minIdx(st, left, least_idx - 1);
//	int right_minIdx = calculate_minIdx(st, least_idx + 1, right);
//
//	unsigned long int left_max_area = getMaxArea(st, left, least_idx - 1, left_minIdx);
//	unsigned long int right_max_area = getMaxArea(st, left, least_idx - 1, left_minIdx);
//
//}

int main()
{
	int N;
	while (true)
	{
		cin >> N;
		if (N <= 0)
			break;

		vector<unsigned long int> arr;
		for (int i = 0; i < N; i++)
		{
			unsigned long int val;
			cin >> val;
			arr.push_back(val);
		}

		SegmentTree st(arr);
		for (unsigned long int val : st.tree)
			cout << val << " ";


	}
}