#エラトステネスの篩 - miniからmaxiまでの素数をリストで返す。

def primeNums(mini, maxi):
    prime = []
    if mini <= 2: prime.append(2)
    judge = [True for _ in range(maxi+1)]
    for i in range(3, maxi+1, 2):
        if judge[i]:
            if i >= mini: prime.append(i)
            for j in range(i*i, maxi+1, i):
                judge[j] = False
    return prime
