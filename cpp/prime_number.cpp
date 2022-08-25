//エラトステネスの篩 - miniからmaxiまでの素数を配列で返す。
//auto vec_name = prime_num(min, max);

vector<int> prime_num(int mini, int maxi) {
    vector<bool> tmp(maxi-1);
    for (int i=0; i<maxi-1; i++) tmp[i] = true;
    vector<int> ans = {};
    for (int i=2; i<maxi+1; i++) {
        if (tmp[i-2]) {
            if (i >= mini) ans.push_back(i);
            for (int j=i*2-2; j<maxi-1; j+=i) tmp[j] = false;
        }
    }
    return ans;
}
