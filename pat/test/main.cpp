#include <iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<windows.h>
#include<time.h>
using namespace std;
int main()
{
    int temp1,i,n,temp2,temp3,temp4;
    string a[30];
    a[1] = "one";
    a[2] = "two";
    a[3] = "three";
    a[4] = "four";
    a[5] = "five";
    a[6] = "six";
    a[7] = "seven";
    a[8] = "eight";
    a[9] = "nine";
    a[10] = "ten";
    a[11] = "eleven";
    a[12] = "twelve";
    a[13] = "thirteen";
    a[14] = "fourteen";
    a[15] = "fifteen";
    a[16] = "sixteen";
    a[17] = "seventeen";
    a[18] = "eighteen";
    a[19] = "nineteen";
    a[20] = "twenty";
    a[21] = "";
    a[22] = "twenty";
    a[23] = "thirty";
    a[24] = "forty";
    a[25] = "fifty";
    a[26] = "sixty";
    a[27] = "seventy";
    a[28] = "eighty";
    a[29] = "ninety";
    //cout<<a[1];
    //cin>>n;
    for(i=1;i<=9999;i++){
        n=i;
        if(n==0){
            cout<<"zero"<<endl;
            return 0;
        }
        temp1 = n/1000;
        n = n%1000;
        temp2 = n/100;
        n = n%100;
        temp3 = n/10;
        n = n%10;
        temp4 = n;
        if(temp1>0){
            cout<<a[temp1]<<" thousand";
        }
        if(temp2>0){
            if(temp1>0){
                cout<<" ";
            }
            cout<<a[temp2]<<" hundred";
        }
        if((temp2>0||temp1>0)&&(temp3*10+temp4<=10&&temp3*10+temp4>0)){
            cout<<" and";
        }
        if(temp3>1){
            if(temp2>0||temp1>0)
                cout<<" ";
            cout<<a[temp3+20];
        }
        if(temp3==1){
            temp4 = temp4+temp3*10;
        }
        if(temp4>0){
            if(temp3>1||temp2>0||temp1>0)
                cout<<" ";
            cout<<a[temp4];
        }
        cout<<endl;
    }

    return 0;
}
