# Class: UnionFind

class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.ec = [0]*n
    
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]
    
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if self.ec[x] > self.ec[y]:
            self.ec[x] += self.ec[y]+1
            self.par[y] = x
        else:
            self.ec[y] += self.ec[x]+1
            self.par[x] = y

    def par_check(self, x, y):
        return self.find(x) == self.find(y)
