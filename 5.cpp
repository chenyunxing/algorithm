#include<iostream>
#include<cstdlib>
using namespace std;
struct lianbiao{
	int num;
	lianbiao *next;
};
int main(){
	int i,m,n,luck,next=1,sum=0,local=0,max,f;
	lianbiao *head,*a,*temp,*up,*up2;
	cin>>m;
	cin>>n;
	head=(struct lianbiao *)malloc(sizeof(lianbiao));
	//设置初值
	temp=head;
	for(i=1;i<=n;i++){
		a=(struct lianbiao *)malloc(sizeof(lianbiao));
		a->num=i;
		a->next=head;
		temp->next=a;
		temp=temp->next;
	}
	max=n;
	i=2;
	//循环进行删除数字
	while(1){
		//获取在第几个幸运数
		temp=head;
		//将下面将会用到的next重置初值
		next=1;
		for(f=0;f<i;f++){
			temp=temp->next;
		}
		if(local==temp->num){
			i++;
			local=temp->next->num;
		}else{
			local=temp->num;
		}
		//设置循环出口 ,如果链表最后一个数字是幸运数则退出循环
		temp=head;
		while(temp->next!=head) {
			temp=temp->next;
		}
		if(local==max){
			break;
		}
		//设置循环条件
		up=head;
		temp=head->next;
		while(temp!=head){
			//如果序号是当前幸运数的倍数则删除
			if(next%local==0){
				a=temp;
				up->next=temp->next;
				free(a);
				temp=up;
				up=up2;
			}
			up2=up;
			up=temp;
			next++;
			temp=temp->next;
		}
		//获取链表最后一个数字
		while(temp->next!=head) {
			temp=temp->next;
		}
		max=temp->num;
	}
	//开始计数
	temp=head->next;
	while(temp!=head){
		if(temp->num>m)
			break;
		temp=temp->next;
	}
	//在此处上一个循环出来时，链表后面的值为空或者都大于m，即处于n<x<=m之间
	while(temp!=head){
		sum++;
		temp=temp->next;
	}
	//检查链表最后一个数是否为n并且计入m-n区间内，是则减一 ,即去除掉x=m的情况
	if(max==n){
		sum--;
	}
	cout<<sum;
	return 0;
}
