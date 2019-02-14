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
		//	필요한 Tree 크기 = 2^(올림(log2(data size)) + 1)
		tree = vector<unsigned long int>(pow(2, ceil(log2(arr.size())) + 1) + 1);
		init(0, arr.size() - 1, 1);
	}

	inline int init(int left, int right, int node)
	{
		//	원소 하나만 남은 경우
		if (left == right)	return tree[node] = left;

		int mid = (left + right) >> 1;
		//int mid = (left + right) / 2;
		int leftMinIndex = init(left, mid, node << 1);
		int rightMinIndex = init(mid + 1, right, (node << 1) + 1);

		//	왼쪽 자식과 오른쪽 자식 노드 중 작은 높이를 가진 값을 선택하여 그것의 'index'를 저장
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
//	//	좌측 블록 존재
//	if (least_idx - 1 >= left)
//	{
//		int left_minIdx = calculate_minIdx(st, left, least_idx - 1);
//	}
//
//	//	우측 블록 존재
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