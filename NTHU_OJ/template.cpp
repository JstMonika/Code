#include <bits/stdc++.h>
using namespace std;

bool valid(int i)
{
	int ch[10];
	
	int idx = 0;
	while (i)
	{
		ch[idx] = i % 10;
		i /= 10;
		idx++;
	}
	
	for (int k = 0; k < idx; k++)
		if (ch[k] != ch[idx-1-k])
			return false;
	
	return true;
}

int main()
{
	vector<int> prime(40000); 		// 0 means prime.
    prime[1] = 1;
	for (int i = 2; i <= sqrt(40000); i++)
	{
		if (prime[i] == 1)
			continue;
		
		for (int k = i*i; k < 40000; k += i)
			prime[k] = 1;
	}
	
	int a, b;
	cin >> a >> b;
	
	bool first = true;
	for (int i = a; i <= b; i++)
	{
		if (prime[i] == 1)
			continue;
		
		if (valid(i))
		{
			if (first)
			{
				cout << i;
				first = false;
			}
			else
				cout << ' ' << i;
		}
	}
	
	if (first)
		cout << "None";
	
	cout << '\n';
}