#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

// UnionFind
struct UnionFind {
    vector<int> par;
    vector<int> rank;

    UnionFind(int n) {
        rep(i, 0, n) {
            par.push_back(i);
            rank.push_back(0);
        }
        return;
    }

    int find(int x) {
        if (x >= par.size()) {
            return -1;
        }
        if (par.at(x) == x) {
            return x;
        } else {
            par.at(x) = find(par.at(x));
            return par.at(x);
        }
    }

    void unite(int x, int y) {
        if (max(x,y) >= par.size()) {
            return;
        }
        x = find(x);
        y = find(y);
        if (rank.at(x) < rank.at(y)) {
            par.at(x) = y;
        } else {
            par.at(y) = x;
            if (rank.at(x) == rank.at(y)) {
                rank.at(x)++;
            }
        }
        return;
    }

    bool isSame(int x, int y) {
        if (max(x,y) >= par.size()) {
            return false;
        }
        return find(x) == find(y);
    }
};
