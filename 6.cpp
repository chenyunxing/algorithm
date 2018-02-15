#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	char a;
	int i,n,temp=0,num[100000],min=100000,max=0,lost,many;
	cin>>n;
	//将存储数字的数组置零，遇到数字的时候存储方法为【比如遇到7则num[7]=num[7]+1，即存储的为数字出现的次数
	for(i=0;i<100000;i++){
		num[i]=0;
	}
	scanf("%c",&a);//一开始会有一个回车符在此处获取
	for(i=0;i<n;i++){
		//每一轮循环结束后，最后一个字符没有存进数组就进入下一轮循环，因此在此次进行存储，要是最后一个字符为空格，则原本最后一个数字被存储过，多存储一次的是数字0，对数据无影响
		if(temp>max)
			max=temp;
		if(temp<min)
			min=temp;
		num[temp]+=1;
		temp=0;
		while(a=getchar(),a!='\n'&&a!=EOF){
			if(a>='0'&&a<='9'){
				//计算数字
				temp=temp*10+a-'0';
			}else{
				if(temp>max)
					max=temp;
				if(temp<min)
					min=temp;
				num[temp]+=1;
				temp=0;
			}
		}
	}
	//同上在循环结束的时候最后一个数字没有存储，需要另外存储
	if(temp>max)
		max=temp;
	if(temp<min)
		min=temp;
	num[temp]+=1;
	//计算哪一个数字出现了两次，哪一个数字一次也没有出现
	for(i=min+1;i<max;i++){
		if(num[i]==0){
			lost=i;
		}
		if(num[i]==2){
			many=i;
		}
	}
	cout<<lost<<" "<<many;
	return 0;
}
