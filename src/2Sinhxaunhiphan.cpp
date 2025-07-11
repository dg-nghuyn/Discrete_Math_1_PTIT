#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n, X[MAX], OK = true;

void Init(){
	for (int i = 1; i <= n; i++){
		X[i] = 0;
	}
}

void Result(){
	for (int i = 1; i <= n; i++){
		cout << setw(3) << X[i];
	}
	cout << endl;
}

void SinhNP(){
	int i = n;
	while (i > 0 && X[i]){
		X[i] = 0;
		i--;
	}
	if (i > 0){
		X[i] = 1;
	}
	else OK = false;
}

int main (){
	cout << "Nhap n: ";
	cin >> n;
	Init();
	while (OK){
		Result();
		SinhNP();
	}
	return 0;
}