#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n, X[MAX], chuaxet[MAX], Xuoi[MAX], Nguoc[MAX];

void Init(){
	for (int i = 1; i <= n; i++){
		chuaxet[i] = true;
	}
	for (int i = 1; i <= 2*n-1; i++){
		Xuoi[i] = true;
		Nguoc[i] = true;
	}
}

void Result(){
	for (int i = 1; i <= n; i++){
		cout << X[i] << " ";
	}
	cout << endl;
}

void Try(int i){
	for (int j = 1; j <= n; j++){
		if (chuaxet[j] && Xuoi[i-j+n] && Nguoc[i+j-1]){
			X[i] = j;
			chuaxet[j] = false;
			Xuoi[i-j+n] = false;
			Nguoc[i+j-1] = false;
			if (i == n){
				Result();
			}
			else{
				Try(i+1);
			}
			chuaxet[j] = true;
			Xuoi[i-j+n] = true;
			Nguoc[i+j-1] = true;
		}
	}
}

int main (){
	cout << "Nhap n: ";
	cin >> n;
	Init();
	Try(1);
	return 0;
}