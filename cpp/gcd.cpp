/*
 ユークリッドの互除法で最大公約数を求める。
A*B/gcd(A, B) で最小公倍数
*/

#include <bits/stdc++.h>
using namespace std;

// ここから
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

// ここまで
int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}
