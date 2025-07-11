#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n, k, X[MAX];

void Result(){
	for (int i = 1; i <= k; i++){
		cout << X[i] << " ";
	}
	cout << endl;
}

void Try(int i){
	for (int j = X[i-1]+1; j <= n-k+i; j++){
		X[i] = j;
		if (i == k){
			Result();
		}
		else Try(i+1);
	}
}

int main (){
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap k: ";
	cin >> k;
	Try(1);
	return 0;
}