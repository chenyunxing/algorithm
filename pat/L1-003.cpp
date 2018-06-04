#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main(){
    char c;
    map<int,int> sum;
    map<int,int>::iterator it;
    while(scanf("%c",&c)!=EOF){
        if(!(c>='0'&&c<='9'))
            break;
        it=sum.find(c-'0');
        if(it==sum.end())//找不到
        {
            sum.insert(pair<int,int>(c-'0',1));
        }
        else //已在map中
        {
            (it->second)++;
        }
    }
    it = sum.begin();
    while(it!=sum.end()){
        cout<<it->first<<":"<<it->second<<endl;
        it++;
    }
    return 0;
}
