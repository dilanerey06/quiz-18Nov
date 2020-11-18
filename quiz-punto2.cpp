#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void readBin();
void imp();
void rectDerecha(int ite);
void rectArriba(int ite);
void rectAbajo(int ite);
void rectDiag(int ite);
float sum_func;
float max_der=0, max_arr=0, max_aba=0, max_diag=0;
float maxim=0;
float **ptrMatrix; 
int n=20;

int main(){
	ptrMatrix=new float*[n];
	for(int i=0; i<n; ++i){
		ptrMatrix[i]=new float[n];
	}
	readBin();
	imp();
	rectDerecha(0);
	//cout<<"max_der= "<<max_der<<'\n';
	rectArriba(0);
	//cout<<"max_arr= "<<max_arr<<'\n';
	rectAbajo(0);
	//cout<<"max_aba= "<<max_aba<<'\n';
	rectDiag(0);
	//cout<<"max_diag= "<<max_aba<<'\n';
	cout<<"Maxima suma: "<<maxim<<'\n';
	delete[]ptrMatrix;
	return 0;
}

void rectDiag(int ite){
	sum_func=0;
	for(int i=0; i<17; ++i){
		sum_func=ptrMatrix[ite][i]+ptrMatrix[ite+1][i+1]+ptrMatrix[ite+2][i+2]+ptrMatrix[ite+3][i+3];
		if(sum_func>maxim){
			maxim=sum_func;
		}
	}
	if(ite<=15){
		++ite;
		rectDiag(ite);
	}
}

void rectAbajo(int ite){
	sum_func=0;
	for(int i=0; i<17; ++i){
		sum_func=ptrMatrix[i][ite]+ptrMatrix[i+1][ite]+ptrMatrix[i+2][ite]+ptrMatrix[i+3][ite];
		if(sum_func>maxim){
			maxim=sum_func;
		}
	}
	if(ite<=18){
		++ite;
		rectArriba(ite);
	}
}

void rectArriba(int ite){
	sum_func=0;
	for(int i=3; i<n; ++i){
		sum_func=ptrMatrix[i][ite]+ptrMatrix[i-1][ite]+ptrMatrix[i-2][ite]+ptrMatrix[i-3][ite];
		if(sum_func>maxim){
			maxim=sum_func;
		}
	}
	if(ite<=18){
		++ite;
		rectArriba(ite);
	}
}

void rectDerecha(int ite){
	sum_func=0;
	for(int j=0; j<17; ++j){
		sum_func=ptrMatrix[ite][j]+ptrMatrix[ite][j+1]+ptrMatrix[ite][j+2]+ptrMatrix[ite][j+3];
		if(sum_func>maxim){
			maxim=sum_func;
		}
	}
	if(ite<=18){
		++ite;
		rectDerecha(ite);
	}
}

void readBin(){
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

void imp(){
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cout<<ptrMatrix[i][j]<<'\t';
		}
		cout<<'\n';
	}
}	
