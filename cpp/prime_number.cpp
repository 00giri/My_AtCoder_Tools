/*
エラトステネスの篩 - miniからmaxiまでの素数を配列で返す。
auto vec_name = prime_num(min, max);
*/

#include <bits/stdc++.h>
using namespace std;

// ここから
vector<long long> prime_nums(long long mini, long long maxi) {
    vector<long long> prime;
    if (mini <= 2) prime.push_back(2);
    vector<bool> judge(maxi+1, true);
    for (long long i=3; i<=maxi; i+=2) {
        if (judge[i]) {
            if (i >= mini) prime.push_back(i);
            for (long long j=i*i; j<=maxi; j+=i) judge[j] = false;
        }
    }
    return prime;
}
// ここまで
