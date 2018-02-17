#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
struct two{
	int num;
	two *left;
	two *right;
};
char a[100][2000000];
int line=0;
two *head;
void add(two *now,int n){
	if(n<now->num&&now->left==NULL){
		two *temp;
		temp=(struct two *)malloc(sizeof(two));
		temp->left=NULL;
		temp->right=NULL;
		temp->num=n;
		now->left=temp;
		return;
	}else if(n>now->num&&now->right==NULL){
		two *temp;
		temp=(struct two *)malloc(sizeof(two));
		temp->left=NULL;
		temp->right=NULL;
		temp->num=n;
		now->right=temp;
		return;
	}
	if(n<now->num){
		add(now->left,n);
	}else{
		add(now->right,n);
	}
	return;
}
void out(two *now,int i){
	int n,n2,temp1,temp2,temp3;
	char temp;
	//计算当前数字有多少位
	temp2=now->num;
	temp3=1;
	temp1=now->num/10;
	while(temp1!=0){
		a[line][n]=temp2%10+'0';
		temp2=temp2/10;
		temp3++;
		temp1=temp1/10;
	}

	if(now->right!=NULL){
		if(i==0){

		}else{
			temp3+=2;
		}
		if(now->right==NULL&&now->left==NULL){

		}else{
			temp3+=2;
		}
		out(now->right,i+temp3-1);
	}
	for(n=0;n<i;n++){
		a[line][n]='.';
	}
	if(i==0){
		temp2=now->num;
		temp3=1;
		temp1=now->num/10;
		while(temp1!=0){
			a[line][n]=temp2%10+'0';
			temp2=temp2/10;
			n++;
			temp3++;
			temp1=temp1/10;
		}
		a[line][n]=temp2%10+'0';
		//将逆序数字转为正序
		for(n2=0;n2<temp3/2;n2++){
			temp=a[line][n-n2];
			a[line][n-n2]=a[line][n-temp3+1+n2];
			a[line][n-temp3+1+n2]=temp;
		}
	}else{
		a[line][n]='|';
		n++;
		a[line][n]='-';
		n++;
		temp2=now->num;
		temp3=1;
		temp1=now->num/10;
		while(temp1!=0){
			a[line][n]=temp2%10+'0';
			temp2=temp2/10;
			n++;
			temp3++;
			temp1=temp1/10;
		}
		a[line][n]=temp2%10+'0';
		//将逆序数字转为正序
		for(n2=0;n2<temp3/2;n2++){
			temp=a[line][n-n2];
			a[line][n-n2]=a[line][n-temp3+1+n2];
			a[line][n-temp3+1+n2]=temp;
		}
	}
	if(now->right==NULL&&now->left==NULL){
//		cout<<endl;
	}else{
		n++;
		a[line][n]='-';
		n++;
		a[line][n]='|';
		n++;
	}
	line++;
	//计算当前数字有多少位
	temp2=now->num;
	temp3=1;
	temp1=now->num/10;
	while(temp1!=0){
		a[line][n]=temp2%10+'0';
		temp2=temp2/10;
		temp3++;
		temp1=temp1/10;
	}
	if(now->left!=NULL){
		if(i==0){

		}else{
			temp3+=2;
		}
		if(now->right==NULL&&now->left==NULL){

		}else{
			temp3+=2;
		}
		out(now->left,i+temp3-1);
	}
}
int main(){
	int n,sum=0,i,f;
	head=(struct two *)malloc(sizeof(head));
	cin>>n;
	sum++;
	head->left=NULL;
	head->right=NULL;
	head->num=n;
	while(scanf("%d",&n)!=EOF){
		sum++;
		add(head,n);
//		cout<<n<<endl;
	}
	out(head,0);
	for(n=0;n<sum;n++){
		for(i=0;i<strlen(a[n]);i++){
			if((a[n][i]=='|'&&a[n][i+1]=='-')||(a[n][i]=='-'&&a[n][i+1]=='|')){
				for(f=0;f<sum;f++){
					if(a[f][i]=='|'){
						break;
					}
				}
				if(f<n){
					for(f=f+1;f<n;f++){
						if(a[f][i]=='.'){
							a[f][i]='|';
						}
					}
				}
				for(f=n+1;f<sum;f++){
					if(a[f][i]=='|'){
						break;
					}
				}
				if(f!=sum){
					for(f=f-1;f>n;f--){
						if(a[f][i]=='.'){
							a[f][i]='|';
						}
					}
				}
			}
		}
	}
	if(sum==1){
		cout<<a[n]<<"-|";
		return 0;
	}
	for(n=0;n<sum;n++){
		cout<<a[n]<<endl;
	}

	return 0;
}
