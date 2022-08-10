#ユークリッドの互除法で最大公約数を求める。
#A*B//gcd(A, B) で最小公倍数

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)
