#include<iostream>
using namespace std;
int main(){
    int i,n;
    long long int sum=1,sumall=0;
    cin>>n;
    for(i=1;i<=n;i++){
        sum=sum*i;
        sumall=sumall+sum;
    }

    cout<<sumall;
}
