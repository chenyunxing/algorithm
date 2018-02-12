#include<iostream>
#include<cstring>
using namespace std;
char* add(char* a,char* b){
	char c[1000],d[1000];
	int i,f,z=0;
	for(i=0;i<1000;i++){
		c[i]=0;
		d[i]=0;
	}
	//进行加法运算
	for(i=strlen(a)-1,f=strlen(b)-1;i>=0||f>=0;f--,i--,z++){
		c[z]=a[i]+b[f]-'0';
		if(c[z]<'0'){
			c[z]=c[z]+'0';
		}
	}
	//进行十进制
	for(i=0;i<strlen(c);i++){
		if(c[i]-'0'>9){
			c[i+1]=c[i+1]+(c[i]-'0')/10;
			c[i]=(c[i]-'0')%10+'0';
			if(c[i+1]<'0'){
				c[i+1]=c[i+1]+'0';
			}
		}
	}
	//将倒着的数字正着存放
	for(i=0;i<strlen(c);i++){
		d[strlen(c)-i-1]=c[i];
	}
	return d;
}
char* multiplication(char* a,char* b){
	char c[1000],d[1000];
	int i,f,z=0;
	for(i=0;i<1000;i++){
		c[i]=0;
		d[i]=0;
	}
	//遍历两种情况，进行算法运算。值得注意的是，需要把数值倒着存放，这样才能方便进行十进制
	if(strlen(a)<strlen(b)){
		for(i=strlen(a)-1;i>=0;i--){
			for(f=strlen(b)-1;f>=0;f--){
				if(c[strlen(b)+strlen(a)-2-(i+f)]<'0'){
					c[strlen(b)+strlen(a)-2-(i+f)]='0';
				}
				c[strlen(b)+strlen(a)-2-(i+f)]=(a[i]-'0')*(b[f]-'0')+c[strlen(b)+strlen(a)-2-(i+f)];
			}
		}
	}else{
		for(i=strlen(b)-1;i>=0;i--){
			for(f=strlen(a)-1;f>=0;f--){
				if(c[strlen(b)+strlen(a)-2-(i+f)]<'0'){
					c[strlen(b)+strlen(a)-2-(i+f)]='0';
				}
				c[strlen(b)+strlen(a)-2-(i+f)]=(a[f]-'0')*(b[i]-'0')+c[strlen(b)+strlen(a)-2-(i+f)];
			}
		}
	}
	//遍历每一个数值，进行十进位计算 【这里是关键点】
	for(i=0;i<strlen(c);i++){
		if(c[i]-'0'>9){
			c[i+1]=c[i+1]+(c[i]-'0')/10;
			c[i]=(c[i]-'0')%10+'0';
			if(c[i+1]<'0'){
				c[i+1]=c[i+1]+'0';
			}
		}
	}
	//将倒着存放的数字正过来
	for(i=0;i<strlen(c);i++){
		d[strlen(c)-i-1]=c[i];
	}
	i=0;
	//遍历左边为0开头的情况，如123*0得出结果000
	while(d[i]=='0'){
		i++;
	}
	//进行去掉左0前导
	if(i!=strlen(d)){
		for(f=0;f<strlen(d);f++){
			d[f]=d[f+i];
		}
	}else{
		z=strlen(d);//这一部的原因是因为在下面循环使用strlen(d)的话
//		以123*0举例得出结果为000，然后遍历第一个0时获得第四位的'/0'然后下一轮循环对比条件f<strlen(d)直接跳出循环
		for(f=0;f<z;f++){
			d[f]=d[f+i];
		}
		d[0]='0';
	}
	return d;
}
int main(){
	char s1[1000],s2[1000];
	cin>>s1;
	cin>>s2;
	cout<<multiplication(s1,s2)<<endl;
	return 0;
} 
