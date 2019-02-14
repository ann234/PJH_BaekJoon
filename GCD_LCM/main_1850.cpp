#include <iostream>

using namespace std;

int main()
{
	unsigned long long int fst, snd;
	cin >> fst >> snd;

	if (snd > fst)
	{
		unsigned long long int tmp = fst;
		fst = snd;
		snd = tmp;
	}

	while (true)
	{
		unsigned long long int left = fst % snd;
		if (left == 0)
			break;
		
		fst = snd;
		snd = left;
	}

	for (unsigned long i = 0; i < snd; i++)
		cout << 1;
}