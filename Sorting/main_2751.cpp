#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void heap_sort(std::vector<int> &arr);
std::vector<int> make_heap(std::vector<int> &arr);
int pop_heap(std::vector<int> &heap);

int main()
{
	time_t start = clock();

	int N;
	cin >> N;
	std::vector<int> arr(N, 0);
	for (int i = 0, val; i < N; i++)
	{
		cin >> val;
		arr[i] = val;
	}

	/*std::vector<int> arr(100000);
	for (int i = 0; i < 100000; i++)
		arr[i] = i;*/

	heap_sort(arr);
	cout << (float)(clock() - start) / CLOCKS_PER_SEC << endl;

	for (int val : arr)
		printf("%d\n", val);
	return 0;
}

//	O(nlogn)
void heap_sort(std::vector<int> &arr)
{
	std::vector<int> heap = make_heap(arr);

	int cnt = arr.size() - 1;
	//	O(n)
	while (heap.size() > 0)
	{
		//	O(logn)
		arr[cnt--] = pop_heap(heap);
	}
}

std::vector<int> make_heap(std::vector<int> &arr)
{
	std::vector<int> heap;
	
	//	Array�� ��ȯ�ϸ鼭
	for (int i = 0; i < arr.size(); i++)
	{
		//	i��° ���� heap�� ���� �ֱ�
		heap.push_back(arr[i]);

		//	Heap ����
		int curr = heap.size() - 1;
		int parent = (curr / 2) + (curr % 2) - 1;
		//	�θ� ���� �� ����
		while (parent >= 0)
		{
			//	�θ𺸴� ���� ū ��� ��ü
			if (heap[curr] > heap[parent])
			{
				int temp = heap[parent];
				heap[parent] = heap[curr];
				heap[curr] = temp;
				
				curr = parent;
				parent = (curr / 2) + (curr % 2) - 1;
			}
			else
				break;
		}
	}

	return heap;
}

//	O(logn)
int pop_heap(std::vector<int> &heap)
{
	int head = heap[0];
	if (heap.size() == 1)
	{
		heap.pop_back();
		return head;
	}

	//	head�� tail�� ��ü
	heap[0] = heap[heap.size() - 1];
	//	���� ū ���̿��� head�� ����
	heap.pop_back();
	//	Heap ����
	int curr = 0;
	while (true)
	{
		int left = (curr + 1) * 2 - 1;	//	���� �ڽ�
		int right = left + 1;	//	������ �ڽ�
		int child_idx = left;
		if (child_idx > heap.size() - 1)	//	�ڽ��� �������� �ʴ� ���
			break;
		if (heap.size() > right)	//	������ �ڽ��� �����ϴ� ���
		{
			//	���� �ڽİ� ������ �ڽ� �� ū ���� ��ü������� ����
			if (heap[right] > heap[left])
				child_idx = right;
		}

		//	���� ��尡 �ڽĺ��� ���� ���
		if (heap[curr] < heap[child_idx])
		{
			//	��ü
			int temp = heap[curr];
			heap[curr] = heap[child_idx];
			heap[child_idx] = temp;
			//	���� �����ġ �ٲ�
			curr = child_idx;
		}
		else
			break;
	}

	return head;
}