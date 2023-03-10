#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

long long modPow(int x, int n, int mod) {
    long long ans = 1;
    while (n) {
        if (n&1) ans = ans*x%mod;
        x = x*x%mod;
        n >>=1;
    }
    return ans;
}
