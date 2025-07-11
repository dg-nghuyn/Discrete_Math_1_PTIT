#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int n, k, X[MAX], OK = true;

void Init(){
	k = 1;
	X[k] = n;
}

void Result(){
	for (int i = 1; i <= k; i++){
		cout << X[i] << " ";
	}
	cout << endl;
}

void SinhPC(){
	int j, R, S, D;
	int i = k;
	while (i > 0 && X[i] == 1){
		i--;
	}
	if (i > 0){
		X[i] = X[i]-1;
		D = k-i+1;
		R = D/X[i];
		S = D%X[i];
		k = i;
		if (R > 0){
			for (j = i+1; j <= i+R; j++){
				X[j] = X[i];
			}
			k+=R;
		}
		if (S > 0){
			k+=1;
			X[k] = S;
		}
	}
	else OK = false;
}

int main (){
	cout << "Nhap n: ";
	cin >> n;
	Init();
	while (OK){
		Result();
		SinhPC();
	}
	return 0;
}