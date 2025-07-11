/*
Duong Thi Ngoc Huyen - B23DCAT139
Bai toan nguoi du lich - phuong phap duyet toan bo
*/

#include<bits/stdc++.h>
using namespace std;

int N; // So thanh pho
vector<vector <int>> c; // Chi phi giua cac thanh pho
vector<int> x; // Luu hanh trinh
vector<int> xopt; //Hanh trinh toi uu
int cost_min = INT_MAX; //Chi phi toi uu

void nhap(){
	cout << "So thanh pho: ";
	cin >> N;
	
	c.resize(N, vector<int>(N));
	x.resize(N);
	xopt.resize(N);
	
	cout << "Ma tran chi phi: " << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> c[i][j];
		}
	}
	
	for (int i = 0; i < N; i++){
		x[i] = i;
	}
}

int check_cost(){
	int sum = 0;
	for (int i = 0; i < N-1; i++){
		sum += c[x[i]][x[i+1]];
	}
	sum += c[x[N-1]][x[0]];
	return sum;
}

void duyet(){
	do{
		int tmp = check_cost();
		if(tmp < cost_min){
			cost_min = tmp;
			xopt = x;
		}
	}
	while (next_permutation(x.begin()+1, x.end()));
}

void in(){
	cout << "Chi phi toi uu: " << cost_min << endl;
	cout << "Hanh trinh: ";
	for (int i = 0; i < N; i++){
		cout << xopt[i] + 1 << " -> ";
	}
	cout << xopt[0] + 1 << endl;
}

int main (){
	nhap();
	duyet();
	in();
	return 0;
}