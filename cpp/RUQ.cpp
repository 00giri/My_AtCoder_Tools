#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

// SegmentTree(RUQ)
template <typename T>
struct RUQ
{
  vector<T> data;
  vector<T> memo;
  const int n;
  const T INF = numeric_limits<T>::max();

  RUQ(int n_) : n(n_)
  {
    int tmp = 1;
    while (tmp < n_) tmp <<= 1;
    data.resize(tmp*2-1, INF);
    memo.resize(tmp*2-1, INF);
  }

  void eval(int ind) {
    if (memo[ind] == INF) return;
    if (ind < (data.size()+1)/2-1) {
      memo[ind*2+1] = memo[ind];
      memo[ind*2+2] = memo[ind];
    }
    data[ind] = memo[ind];
    memo[ind] = INF;
  }

  void update(int a, int b, T x, int ind=0, int l=0, int r=-1) {
    if (r == -1) r = (data.size()+1)/2;
    if (a>=b || a<0 || b>n) return;
    eval(ind);
    if (a<=l && r<=b) {
      memo[ind] = x;
      eval(ind);
    } else if (a<r && l<b) {
      update(a, b, x, ind*2+1, l, (l+r)/2);
      update(a, b, x, ind*2+2, (l+r)/2, r);
      data[ind] = min(data[ind*2+1], data[ind*2+2]);
    }
  }

  T get(int a, int b, int ind=0, int l=0, int r=-1) {
    eval(ind);
    if (r == -1) r = (data.size()+1)/2;
    if (a>=b || a<0 || b>n) return -1;
    if (a>=r || b<=l) return INF;
    else if (a<=l && r<=b) return data[ind];
    else return min(get(a, b, ind*2+1, l, (l+r)/2), get(a, b, ind*2+2, (l+r)/2, r));
  }
};
