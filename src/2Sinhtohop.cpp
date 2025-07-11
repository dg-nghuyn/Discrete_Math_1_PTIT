#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n, k, X[MAX], OK = true;

void Init(){
	for (int i = 1; i <= k; i++){
		X[i] = i;
	}
}

void Result(){
	for (int i = 1; i <= k; i++){
		cout << setw(3) << X[i];
	}
	cout << endl;
}

void SinhTH(){
	int i = k;
	while (i > 0 && X[i] == n-k+i){
		i--;
	}
	if (i > 0){
		X[i] += 1;
		for (int j = i+1; j <= k; j++){
			X[j] = X[i] + j-i;
		}
	}
	else OK = false;
}

int main (){
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap k: ";
	cin >> k;
	Init();
	while (OK){
		Result();
		SinhTH();
	}
	return 0;
}