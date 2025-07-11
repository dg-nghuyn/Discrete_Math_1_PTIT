#include<bits/stdc++.h>
#define MAX 100

using namespace std;

int n, k, X[MAX];

void Init(){
	cout << "Nhap n:";
	cin >> n;
	cout << "Nhap k:";
	cin >> k;
	for (int i = 1; i <= n; i++){
		X[i] = 0;
	}
}

void Result(){
	for (int i = 1; i <= n; i++){
		cout << X[i] << " ";
	}
	cout << endl;
}

bool Check(){
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (X[i] == 1){
			cnt++;
		}
	}
	return cnt == k;
}

void Try(int i){
	if (i > n){
		if (Check()){
			Result();
		}
		return;
	}
	for (int j = 0; j <= 1; j++){
		X[i] = j;
		Try(i+1);
	}
}

int main (){
	Init();
	Try(1);
	return 0;
}