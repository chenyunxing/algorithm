#include<iostream>
using namespace std;
int main(){
	int i,n,z,temp,sum=1;
	cin>>n;
	cin>>z;
	if(z<0){
		z=-z;
	}
	for(i=0;i<n-1;i++){
		cin>>temp;
		if(temp<0){
			if(-temp>z)
				sum++;
		}else{
			if(temp<z)
				sum++;
		}
	}
	cout<<sum;
}
