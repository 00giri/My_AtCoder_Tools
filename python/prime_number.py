#エラトステネスの篩 - miniからmaxiまでの素数をリストで返す。

def primeNum2(mini, maxi):
    prime = []
    if mini <= 2: prime.append(2)
    judge = [0 for _ in range(maxi+1)]
    for i in range(3, maxi+1, 2):
        if not judge[i]:
            if i >= mini: prime.append(i)
            for j in range(i*i, maxi+1, i):
                judge[j] = 1
    return prime
