#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n, X[MAX], chuaxet[MAX];

void Init(){
	for (int i = 1; i <= n; i++){
		chuaxet[i] = true;
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
		if (chuaxet[j]){
			X[i] = j;
			chuaxet[j] = false;
			if (i == n){
				Result();
			}
			else{
				Try(i+1);
			}
			chuaxet[j] = true;
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