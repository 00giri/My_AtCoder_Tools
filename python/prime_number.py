#エラトステネスの篩 - miniからmaxiまでの素数をリストで返す。

def primeNum(mini, maxi):
    sosuu = list(range(maxi+1))
    sosuu2 = []
    
    for i in range(2, maxi+1):
        if sosuu[i] != "-":
            if i >= mini: sosuu2.append(sosuu[i])
            for j in range(i*2,maxi+1,i):
                sosuu[j] = "-"
    return sosuu2
