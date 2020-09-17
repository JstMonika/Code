#include <bits/stdc++.h>
using namespace std;

int main()
{
	int c;
	cin >> c;
	
	while (c--)
	{
		long long r, b, k;
		cin >> r >> b >> k;
		
		long long bigger = max(r, b);
		long long smaller = min(r, b);
		
		long long count = bigger / smaller;
		if (!(bigger % smaller))
			count--;
			

		if (count >= k and (!(bigger+smaller == 3 and k == 1)))
			cout << "REBEL" << endl;
		else 
			cout << "OBEY" << endl;
	}
}