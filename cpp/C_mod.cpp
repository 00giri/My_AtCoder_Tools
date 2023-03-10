#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

// nCr mod m modPowもセット

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

struct Cmod {
    vector<int> fct;
    vector<int> inv;
    int mod;

    Cmod(int Nmax, int Mod) {
        fct.resize(Nmax+1);
        inv.resize(Nmax+1);
        mod = Mod;

        long long num = 1;
        fct[0] = 1;
        rep(i, 1, Nmax+1) {
            num = num*i%mod;
            fct[i] = num;
        }

        num = modPow(num, mod-2, mod);
        inv[Nmax] = num;
        inv[0] = 1;
        for (int i=Nmax; i>1; i--) {
            num = num*i%mod;
            inv[i-1] = num;
        }
    }

    int CMod(int n, int r) {
        r = min(r, n-r);
        if (r) {
            return (long long)fct[n]*inv[r]%mod*inv[n-r]%mod;
        } else {
            return 1;
        }
    }
};
