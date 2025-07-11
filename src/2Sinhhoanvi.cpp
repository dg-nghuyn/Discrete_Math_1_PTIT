#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n, X[MAX], OK = true;

void Init(){
	for (int i = 1; i <= n; i++){
		X[i] = i;
	}
}

void Result(){
	for (int i = 1; i <= n; i++){
		cout << setw(3) << X[i];
	}
	cout << endl;
}

void SinhHV(){
	int i = n;
	while (i > 1 && X[i-1] > X[i]){
		i--;
	}
	if (i > 1){
		int j = n;
		while (X[i-1] > X[j]){
			j--;
		}
		swap(X[i-1], X[j]);
		sort(X+i, X+n+1);
	}
	else{
		OK = false;
	}
}

int main (){
	cout << "Nhap n: ";
	cin >> n;
	Init();
	while (OK){
		Result();
		SinhHV();
	}
	return 0;
}