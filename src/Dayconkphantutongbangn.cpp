//Cau 4 de thi so 3
#include <bits/stdc++.h>
using namespace std;
int a[100], n, m, k, ok;
void ktao(){
	for(int i = 1; i <= n; i++){
		a[i] = 0;
	}
}
void sinh(){
	int i = n;
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i == 0){
		ok = 0;
	}
	else{
		a[i] = 1;
	}
}

bool check(int b[]){
	int cnt = 0;
	int cnt1 = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			cnt += b[i];
			cnt1++;
		}
	}
	if(cnt == k && cnt1 == m) return true;
	else return false;
}

int main(){
	cin >> n >> k >> m;
	// n la so phan tu, k la tong, m la so phan tu tap con
	int b[n+1]; b[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	ok = 1;
	ktao();
	while(ok){
		if(check(b)){
			for(int i = 1; i <= n; i++){
				if(a[i] == 1) cout << b[i] << " ";
			}
			cout << endl;
		}
		sinh();
	}
}