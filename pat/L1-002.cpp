#include<iostream>
using namespace std;
int main(){
	int s1[25],s2[25],n,i,f,z=0,lev,yu;
	cin>>n;
	char a;
	cin>>a;
	s1[0]=1;
	s2[0]=1;
	s1[1]=7;
	s2[1]=3;
	s1[2]=17;
	s2[2]=5;
	for(i=3;i<25;i++){
        s2[i]=s2[i-1]+2;
        s1[i]=s1[i-1]+2*s2[i];
	}
    for(i=1;i<25;i++){
        if(n<s1[i]){
            lev = i-1;
            break;
        }
    }
	for(i=lev;i>=0;i--){
		for(f=0;f<s2[lev]-s2[i];f+=2)
			cout<<' ';
		for(f=0;f<s2[i];f++)
			cout<<a;
		cout<<endl;
	}
	for(i=1;i<=lev;i++){
		for(f=0;f<s2[lev]-s2[i];f+=2)
			cout<<' ';
		for(f=0;f<s2[i];f++)
			cout<<a;
		cout<<endl;
	}
	cout<<n - s1[lev];
}
