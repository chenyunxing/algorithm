#include<iostream>
#include<cstring>
using namespace std;
//a为原数组,b为按大小排序的数组,c为b的树状数组,d为暂存的不开心值 ,e为等差数列存储不高兴值的递增值
int a[100001],b[1000003],c[1000003],d[1000003];
long long int e[100002];
//位运算
int lowbit(int x)
{
    return x&(-x);  
}
//定义修改C数组的函数，第一个值代表数组位置，第二个代表数组值，在此题中只需默认加一
void update(int local,int num){
	int n=local,add;
	add=num-b[local];
	b[local]=num;
	while(n<1000002){
		c[n]+=add;
		n+=lowbit(n);
	}
}
//查询前多少区间的和
int read(int i){
	int n=i,sum=0;
	while(n!=0){
		sum+=c[n];
		n-=lowbit(n);
	}
	return sum;
}
//清零函数
void ini(){
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
}
int main(){
	int i,n;
	long long int sum=0;
	cin>>n;
	ini();
	for(i=0;i<n;i++){
		cin>>a[i];//按顺序存储进来的小朋友身高
		update(a[i]+1,b[a[i]+1]+1);//修改b和c数组,
		d[i]=i-read(a[i])-b[a[i]+1]+1;//计算在第i个小朋友进来时，前面比他高的人数
	}
	ini();
	for(i=n-1;i>=0;i--){
		update(a[i]+1,b[a[i]+1]+1);//修改b和c数组,
		d[i]+=read(a[i]);//计算在第i个小朋友进来时，后面比他矮的人数
	}
	e[1]=1;
	for(i=2;i<n+1;i++){
		e[i]=e[i-1]+i;
	}
	for(i=0;i<n;i++){
		sum+=e[d[i]];
	}
	cout<<sum;
	return 0;
}
