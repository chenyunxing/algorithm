#include<iostream>
using namespace std;
int main(){
	int n,z,i,f,temp=1;//temp=1在已知后+.$temp=0在已知后+$.
	cin>>n;
	char** c;
	c=new char* [n*4+6];
	for(i=0;i<n*4+6;i++){
		c[i]=new char [n*4+6];
	}
	for(i=1;i<n*4+6;i++){
		for(f=1;f<n*4+6;f++){
			c[i][f]='1';
		}
	}
	for(i=1;i<(n*4+6)/2;i++){
		if(i==1){
			c[i][1]='.';
			c[(n*4+6)-i][1]='.';
			c[i][2]='.';
			c[(n*4+6)-i][2]='.';
			for(f=3;f<n*4+4;f++){
				c[i][f]='$';
				c[(n*4+6)-i][f]='$';
			}
			c[i][f]='.';
			c[i][f+1]='.';
			c[(n*4+6)-i][f]='.';
			c[(n*4+6)-i][f+1]='.';
			//列
			c[1][i]='.';
			c[2][i]='.';
			for(f=3;f<n*4+4;f++){
				c[f][i]='$';
			}
			c[f][i]='.';
			c[f+1][i]='.';

			c[1][(n*4+6)-i]='.';
			c[2][(n*4+6)-i]='.';
			for(f=3;f<n*4+4;f++){
				c[f][(n*4+6)-i]='$';
			}
			c[f][(n*4+6)-i]='.';
			c[f+1][(n*4+6)-i]='.';
		}else{
			//遍历已知
			f=i;
			if(temp==1){
				c[i][f]='.';
				f++;
				c[i][f]='$';
				f++;
				for(z=0;z<(n*4+5)-(i+1)*2;f++,z++){
					c[i][f]='.';
				}
				if((n*4+5)-(i+1)*2<=0){
					f--;
				}
				c[i][f]='$';
				f++;
				c[i][f]='.';
				//倒数行
				for(z=i;z<(n*4+6);z++){
					c[(n*4+6)-i][z]=c[i][z];
				}
				//正数列
				for(z=i;z<(n*4+6);z++){
					c[z][i]=c[i][z];
				}
				//倒数列
				for(z=i;z<(n*4+6);z++){
					c[z][(n*4+6)-i]=c[i][z];
				}
				//改变temp
				temp=0;
			}else{
				c[i][f]='$';
				f++;
				c[i][f]='.';
				f++;
				for(z=0;z<(n*4+5)-(i+1)*2;f++,z++){
					c[i][f]='$';
				}
				c[i][f]='.';
				f++;
				c[i][f]='$';
				//倒数行
				for(z=i;z<(n*4+6);z++){
					c[(n*4+6)-i][z]=c[i][z];
				}
				//正数列
				for(z=i;z<(n*4+6);z++){
					c[z][i]=c[i][z];
				}
				//倒数列
				for(z=i;z<(n*4+6);z++){
					c[z][(n*4+6)-i]=c[i][z];
				}
				//改变temp
				temp=1;
			}
		}
	}
	if(temp==1){
		c[(n*4+6)/2][(n*4+6)/2]='.';
	}else{
		c[(n*4+6)/2][(n*4+6)/2]='$';
	}
	for(i=1;i<n*4+6;i++){
		for(f=1;f<n*4+6;f++){
			cout<<c[i][f];
		}
		cout<<endl;
	}
	return 0;
}