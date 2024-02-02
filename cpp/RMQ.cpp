#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

// SegmentTree(RMQ)
template <typename T>
struct RMQ
{
  vector<T> data;
  const int n;
  const T INF = numeric_limits<T>::max();

  RMQ(int n_) : n(n_)
  {
    int tmp = 1;
    while (tmp < n_) tmp <<= 1;
    data.resize(tmp*2-1, INF);
  }

  void update(int ind, T x) {
    ind += (data.size()+1)/2-1;
    data[ind] = x;
    while (ind > 0) {
      ind = (ind-1)/2;
      data[ind] = min(data[ind*2+1], data[ind*2+2]);
    }
  }

  T get(int a, int b, int ind=0, int l=0, int r=-1) {
    if (r == -1) r = (data.size()+1)/2;
    if (a>=b || a<0 || b>n) return -1;
    if (a>=r || b<=l) return INF;
    else if (a<=l && r<=b) return data[ind];
    else return min(get(a, b, ind*2+1, l, (l+r)/2), get(a, b, ind*2+2, (l+r)/2, r));
  }
};