/* 
Duong Thi Ngoc Huyen - B23DCAT139
Bai toan cai tui - phuong phap duyet toan bo
*/

#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

int N, B; // B là trọng lượng túi, N là số đồ vật
vector<int> a; // a[i] là trọng lượng đồ vật i
vector<int> c; // c[i] là giá trị sử dụng đồ vật i
vector<int> x; // các phương án
vector<int> xopt; // phương án tối ưu
int fopt = -1; // giá trị tối ưu

void nhap(){
    cout << "So loai do vat: ";
    cin >> N;

    a.resize(N);
    c.resize(N);
    x.resize(N);
    xopt.resize(N);

    cout << "Trong luong tui: ";
    cin >> B;

    cout << "Vector trong luong: ";
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    cout << "Vector gia tri su dung: ";
    for (int i = 0; i < N; i++){
        cin >> c[i];
    }
}

bool check_b(){
    int weight = 0;
    for (int i = 0; i < N; i++){
        weight += a[i] * x[i];
    }
    if (weight > B){
        return false;
    }
    else return true;
}

void check_sum(){
    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += x[i] * c[i];
    }
    if(fopt < sum){
        fopt = sum;
        for (int i = 0; i < N; i++){
            xopt[i] = x[i];
        }
    }
}

void duyet(int i){
    for (int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == N - 1){
            if (check_b()){
                check_sum();
            }
        }
        else duyet(i + 1);
    }
}

void in(){
    cout << "Ket qua toi uu: ";
    cout << fixed << setprecision(1) << (double)fopt << endl;
    cout << "Phuong an toi uu: ";
    for (int i = 0; i < N; i++){
        cout << xopt[i] << " ";
    }
    cout << endl;
}

int main (){
    nhap();
    duyet(0);
    in();
    return 0;
}
