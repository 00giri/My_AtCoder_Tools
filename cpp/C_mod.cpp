#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

// nCr mod m modPowもセット
long long modPow(int x, int n, int mod) {
    long long ans = 1;
    while (n) {
        if (n&1) ans = ans*x%mod;
        x = x*x%mod;
        n >>=1;
    }
    return ans;
}

struct Cmod {
    vector<int> fct;
    vector<int> inv;
    int mod;

    Cmod(int Nmax, int Mod) {
        fct.resize(Nmax);
        inv.resize(Nmax);
        mod = Mod;

        long long num = 1;
        rep(i, 0, Nmax) {
            num = num*(i+1)%mod;
            fct[i] = num;
        }

        num = modPow(num, mod-2, mod);
        for (int i=Nmax; i>1; i--) {
            num = num*i%mod;
            inv[i-1] = num;
        }
    }

    int CMod(int n, int r) {
        r = min(r, n-r);
        if (r) {
            return fct[n-1]*inv[r]%mod*inv[n-r]%mod;
        } else {
            return 1;
        }
    }
};
