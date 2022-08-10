#組み合わせの数を求める

def C(n, r):
    r = min(n-r,r)
    tmp = 1
    for i in range(n-r+1, n+1): tmp *= i
    tmp2 = 1
    for i in range(2, r+1): tmp2 *= i
    return tmp//tmp2
