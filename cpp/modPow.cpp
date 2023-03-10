#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int modPow(int x, int n, int mod) {
    long long ans = 1;
    long long x2 = x;
    while (n) {
        if (n&1) ans = ans*x2%mod;
        x2 = x2*x2%mod;
        n >>=1;
    }
    return ans;
}
