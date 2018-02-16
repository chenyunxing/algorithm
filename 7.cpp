#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct two{
	int num;
	two *left;
	two *right;
};
char a[100][10000];
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
	int n;
	if(now->right!=NULL){
		out(now->right,i+1);
	}
	for(n=0;n<i*2;n++){
		cout<<".";
	}
	if(i==0){
		cout<<now->num;
	}else{
		cout<<"|-"<<now->num;
	}
	if(now->right==NULL&&now->left==NULL){
		cout<<endl;
	}else{
		cout<<"-|"<<endl;
	}
	if(now->left!=NULL){
		out(now->left,i+1);
	}
}
int main(){
	int n;
	head=(struct two *)malloc(sizeof(head));
	cin>>n;
	head->left=NULL;
	head->right=NULL;
	head->num=n;
	while(cin>>n,n!=-1){
		
		add(head,n);
//		cout<<n<<endl;
	}
	
	out(head,0);
}
