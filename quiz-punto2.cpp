#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void readBin(float **ptrMatrix, int n);
void imp(float **ptrMatrix, int n);
void rect(float **ptrMatrix, int n);

int main(){
	float **ptrMatrix;
	int n=20;
	ptrMatrix=new float*[n];
	for(int i=0; i<n; ++i){
		ptrMatrix[i]=new float[n];
	}
	readBin(ptrMatrix, n);
	imp(ptrMatrix, n);
	rect(ptrMatrix, n);
	delete[]ptrMatrix;
	return 0;
}

void rect(float **ptrMatrix, int n){
	float sum[4], max_sum=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++i){
			sum[4]={};
			if(i<17){
				sum[0]=ptrMatrix[i][j]+ptrMatrix[i+1][j]+ptrMatrix[i+2][j]+ptrMatrix[i+3][j];
			}
			if(j<17){
				sum[1]=ptrMatrix[i][j]+ptrMatrix[i][j+1]+ptrMatrix[i][j+2]+ptrMatrix[i][j+3];
			}
			if(j<17&&i<17){
				sum[2]=ptrMatrix[i][j]+ptrMatrix[i+1][j+1]+ptrMatrix[i+2][j+2]+ptrMatrix[i+3][j+3];
			}
			if (i>2){
				sum[3]=ptrMatrix[i][j]+ptrMatrix[i-1][j]+ptrMatrix[i-2][j]+ptrMatrix[i-3][j];
			}
			for(int k=0; k<4; ++k){
				if(sum[k]>max_sum){
					max_sum=sum[k];
				}
			}
		}
	}
	cout<<"Suma maxima: "<<max_sum<<'\n';
}

void readBin(float **ptrMatrix, int n){
	ifstream file;
	file.open("matriz20x20_float.bin", ios::in | ios::binary);
	if(file.fail()){
		cout<<"EL archivo no fue encontrado"<<'\n';
		exit(1);
	}
	for(int i=0; i<n; ++i){
		file.read((char *)&ptrMatrix[i][0], 20*sizeof(float));
	}
	file.close();
}

void imp(float **ptrMatrix, int n){
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cout<<ptrMatrix[i][j]<<'\t';
		}
		cout<<'\n';
	}
}	