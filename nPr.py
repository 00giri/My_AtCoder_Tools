#順列の数を求める。

def P(n, r):
    tmp = 1
    for i in range(n-r+1, n+1): tmp *= i
    return tmp
