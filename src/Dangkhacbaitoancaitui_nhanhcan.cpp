/* 
Duong Thi Ngoc Huyen - B23DCAT139
Dang khac bai toan cai tui - phuong phap nhanh can
*/


#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
    double ratio;
    bool operator<(const Item& other) const {
        return ratio > other.ratio; // So sánh tỷ lệ
    }
};

int n, b, fopt = 0;
vector<Item> items; // Danh sách đồ vật
vector<vector<int>> xopt; // Phương án tối ưu

void nhap() {
    cout << "So loai do vat: ";
    cin >> n;
    cout << "Trong luong tui: ";
    cin >> b;
    items.resize(n);
    cout << "Vector trong luong: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
    }
    cout << "Vector gia tri su dung: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight; // Tính tỷ lệ
    }
    sort(items.begin(), items.end()); // Sắp xếp theo tỷ lệ
}

void in() {
    cout << "Ket qua toi uu: " << fixed << setprecision(1) << (double)fopt << endl;
    cout << "Phuong an toi uu: " << endl;
    for (const auto& opt : xopt) {
        for (int i : opt) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int tinhGioiHan(int k, int tmp_w, int tmp_v) {
    int upper_bound = tmp_v;
    int remaining_weight = b - tmp_w;
    for (int i = k; i < n; i++) {
        if (items[i].weight <= remaining_weight) {
            upper_bound += items[i].value; // Thêm giá trị đầy đủ
            remaining_weight -= items[i].weight;
        } else {
            upper_bound += items[i].value * (double)remaining_weight / items[i].weight; // Thêm theo tỷ lệ
            break;
        }
    }
    return upper_bound;
}

void Try(int k, int tmp_w, int tmp_v, vector<int>& tmp_cnt) {
    if (k == n) {
        if (tmp_v > fopt) {
            fopt = tmp_v;
            xopt.clear(); // Xóa danh sách trước khi thêm phương án mới
            xopt.push_back(tmp_cnt); // Thêm phương án mới
        } else if (tmp_v == fopt) {
            xopt.push_back(tmp_cnt); // Thêm phương án khác
        }
        return;
    }
    
    int upper_bound = tinhGioiHan(k, tmp_w, tmp_v);
    if (upper_bound < fopt) return;
    
    int max_cnt = (b - tmp_w) / items[k].weight;
    for (int x = max_cnt; x >= 0; x--) {
        tmp_cnt[k] = x;
        Try(k + 1, tmp_w + x * items[k].weight, tmp_v + x * items[k].value, tmp_cnt);
    }
}

int main() {
    nhap();
    vector<int> tmp_cnt(n, 0);
    Try(0, 0, 0, tmp_cnt);
    in();
    return 0;
}
