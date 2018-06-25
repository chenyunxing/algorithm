#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map> 
#include <string>
#include<cstring>
using namespace std;
int mirrorReflection(int p, int q) {
    if(p/q==2){
    	return 2;
	}else if(p/q==3){
		return 1;
	} else{
		return 0;
	}
}
int main(){
	string a,b;
	cin>>a;
//	cin>>b;
	cout<<scoreOfParentheses(a);
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
