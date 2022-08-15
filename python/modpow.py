#aのn乗をmodで割ったあまり
def modpow(a, n, mod):
    tmp = 1
    while n > 0:
        if n&1: tmp = tmp*a%mod
        a = a*a%mod
        n >>= 1
    return tmp
