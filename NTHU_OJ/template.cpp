#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll num[10000005]={};
ll tmp[10000005]={};
ll ans;

void mergesort(ll len,ll *arr)
{
	
	if(len<=1) return;
	
	ll leftlen = len/2;
	ll rightlen = len-leftlen;
	ll *leftarr = arr;
	ll *rightarr = arr+leftlen;
	mergesort(leftlen,leftarr);
	mergesort(rightlen,rightarr);
	
	ll l = 0, r = 0, tmplen = 0, lf = 0;
	while(l<leftlen && r<rightlen)
	{
		if(leftarr[l] > rightarr[r])
		{
			while (lf != leftlen && leftarr[lf] <= rightarr[r] * 2) lf++;
			ans += leftlen - lf;
			
			tmp[tmplen++] = rightarr[r++];
		}
		else 
			tmp[tmplen++] = leftarr[l++];
	}
	
	while(l<leftlen) tmp[tmplen++] = leftarr[l++];
	while(r<rightlen) tmp[tmplen++] = rightarr[r++];
	for(int i=0;i<tmplen;i++) arr[i] = tmp[i];
}
int main()
{
	
	ll n,op;
	while(~scanf("%lld %lld",&n,&op))
	{
		ans = 0;
		for(int i=0;i<n;i++)
		scanf("%lld",&num[i]);
		mergesort(n,num);
		if(op==0) printf("%lld\n",ans);
		else printf("%lld\n",num[n-op]);
	}

}