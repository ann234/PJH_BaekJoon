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
	
	//	Array를 순환하면서
	for (int i = 0; i < arr.size(); i++)
	{
		//	i번째 값을 heap의 끝에 넣기
		heap.push_back(arr[i]);

		//	Heap 정렬
		int curr = heap.size() - 1;
		int parent = (curr / 2) + (curr % 2) - 1;
		//	부모가 없을 때 까지
		while (parent >= 0)
		{
			//	부모보다 값이 큰 경우 교체
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

	//	head와 tail을 교체
	heap[0] = heap[heap.size() - 1];
	//	가장 큰 값이였던 head를 제거
	heap.pop_back();
	//	Heap 정렬
	int curr = 0;
	while (true)
	{
		int left = (curr + 1) * 2 - 1;	//	왼쪽 자식
		int right = left + 1;	//	오른쪽 자식
		int child_idx = left;
		if (child_idx > heap.size() - 1)	//	자식이 존재하지 않는 경우
			break;
		if (heap.size() > right)	//	오른쪽 자식이 존재하는 경우
		{
			//	왼쪽 자식과 오른쪽 자식 중 큰 것을 교체대상으로 선택
			if (heap[right] > heap[left])
				child_idx = right;
		}

		//	현재 노드가 자식보다 작은 경우
		if (heap[curr] < heap[child_idx])
		{
			//	교체
			int temp = heap[curr];
			heap[curr] = heap[child_idx];
			heap[child_idx] = temp;
			//	현재 노드위치 바꿈
			curr = child_idx;
		}
		else
			break;
	}

	return head;
}