#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

int main(){
	int n=16, a=1, b=5;
	float h, sum, result;
	result=0;
	sum=0;
	h=float(b-a)/float(n);
	float x[17]={};
	float fx[17]={};
	for(int i=0; i<n+1; ++i){
		if(i==0){
			x[i]=float(a);
		}
		else{
			x[i]=x[i-1]+h;
		}
		fx[i]=sin(x[i])*exp(x[i]);
	}
	for(int j=1; j<=8; ++j){
		sum=sum+(fx[(2*j)-2]+(4*fx[(2*j)-1]+fx[2*j]));
	}
	result=sum*h/float(3);
	cout<<result<<'\n';
	return 0;
}
