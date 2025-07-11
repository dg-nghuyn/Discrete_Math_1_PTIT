#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int k, n, X[MAX], dem = 0, OK = true;

void Init(){
    cout << "Nhap n: ";
    cin >> n;
    k = 1, X[k] = n;
}

void Result(){
//    cout << "Cach chia: " << dem++ << endl;
    for (int i = 1; i <= k; i++){
        cout << X[i] << " ";
    }
    cout << endl;

    for (int j = 1; j <= n-k; j++){
    	for (int i = 1; i <= k; i++){
    		cout << X[i] << " ";
		}
		for (int i = 1; i <= j; i++){
			cout << "0 ";
		}
		cout << endl;
	}
}

void Next(){
    int i = k, j, R, S, D;
    while (i > 0 && X[i] == 1){
        i--;
    }
    if (i > 0){
        X[i] = X[i] - 1;
        D = k - i + 1;
        R = D / X[i];
        S = D % X[i];
        k = i;
        if (R > 0){
            for (j = i + 1; j <= i + R; j++){
                X[j] = X[i];
            }
            k += R;
        }
        if (S > 0){
            k += 1;
            X[k] = S;
        }
    } else OK = false;
}

int main (){
    Init();
    Next();
    while (OK){
    	Result();
        Next();
    }
    return 0;
}