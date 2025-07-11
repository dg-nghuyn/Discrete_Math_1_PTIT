/*
Bai toan quan hau:
Liet ke 8 cach dat quan hau tren ban co de no khong an nhau
Su dung thuat toan quay lui
*/

#include<bits/stdc++.h>
using namespace std;

//Xuoi, Nguoc la cac duong cheo
//A[8] danh dau cac cot da co quan hau

int N = 8;
int Xuoi[15], Nguoc[15], X[8], A[8];

void Result(){
	for (int i = 1; i <= N; i++){
		if (i == N) cout << X[i] << endl;
		else cout << X[i] << ",";
	}
	cout << endl;
}


void Try(int i){
	for (int j = 1; j <= N; j++){
		if (A[j] && Xuoi[i-j+N] && Nguoc[i+j-1]){
			X[i] = j;
			A[j] = false;
			Xuoi[i-j+N] = false;
			Nguoc[i+j-1] = false;
			if (i == N) Result();
			else Try(i+1);
			A[j] = true;
			Xuoi[i-j+N] = true;
			Nguoc[i+j-1] = true;
		}
	}
}

int main (){
	for (int t = 1; t <= N; t++){
		A[t] = 1;
	}
	for (int i = 1; i <= N*2-1; i++){
		Xuoi[i] = Nguoc[i] = 1;
	}
	Try(1);
	return 0; 
}