#include<iostream>
using namespace std;
//1
int main(){
	int i,n;
	long long int a[1001],b[1001],sum;
	cin>>n;
	a[1]=1;
	b[1]=1;
	a[2]=6;
	b[2]=2;
	for(i=3;i<=n;i++){
		b[i]=(b[i-1]*2)%1000000007;
		a[i]=(a[i-1]*2+b[i]+a[i-2]*2*2)%1000000007;
	}
	sum=a[n]*4;
	for(i=2;i<=n-1;i++)
    {
    	sum+=((b[n-i]*2*(a[i-1]*2))*2%1000000007+(b[i-1]*2*(a[n-i]*2)*2)%1000000007)%1000000007;
    	sum%=1000000007;
	}
	if(n==1)
		sum=2;
	cout<<sum;
	return 0;
}
