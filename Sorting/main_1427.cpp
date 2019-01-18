#include <iostream>
#include <vector>
#include <string>

using namespace std;

void bubble_sort(std::vector<int> &arr);

int main()
{
	int val;
	cin >> val;

	string str = std::to_string(val);
	std::vector<int> arr;

	for (char val : str)
		arr.push_back(val - '0');

	bubble_sort(arr);

	for (int val : arr)
		cout << val;

	return 0;
}

void bubble_sort(std::vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}