#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map> 
using namespace std;
struct a{
	int di;
	int pi;
}; 
bool cmp(a a1,a b){
	if(a1.di>b.di){
		return true;
	}else{
		return false;
	}
}
int main(){
	int n,k,i,f,sum=0;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		for(f=1;f<=n;f++){
			if(i%f>=k)
				sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
//int main()
//{
//	int i,f,n1,n2,p[100005],max;
//	a w[100005];
//	cin>>n1;
//	cin>>n2;
//	for(i=0;i<n1;i++){
//		cin>>w[i].di;
//		cin>>w[i].pi;
//	}
//	for(i=0;i<n1;i++){
//		cin>>p[i];
//	}
//	sort(w,w+n1,cmp);
////	for(i=0;i<n1;i++){
////		cout<<w[i].di<<"   "<<w[i].pi<<endl;
////	}
//	for(i=0;i<n2;i++){
//		max = -1;
//		for(f=0;f<n1;f++){
//			if(p[i]>=w[f].di)
//				break;
//		}
//		for(;f<n1;f++){
//			if(w[f].pi>max)
//				max = w[f].pi;
//		}
//		cout<<max<<endl;
//	}
//	return 0; 
//}
