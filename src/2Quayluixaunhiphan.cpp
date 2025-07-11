#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n, X[MAX];

void Result(){
	for (int i = 1; i <= n; i++){
		cout << setw(3) << X[i];
	}
	cout << endl;
}

void Try(int i){
	for (int j = 0; j <= 1; j++){
		X[i] = j;
		if (i == n){
			Result();
		}
		else{
			Try(i+1);
		}
	}
}

int main (){
	cout << "Nhap n: ";
	cin >> n;
	Try(1);
	return 0;
}