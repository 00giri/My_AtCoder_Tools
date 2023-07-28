# Class: UnionFind

class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [0]*n
    
    def root(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.root(self.par[x])
            return self.par[x]
    
    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] +=1

    def isSame(self, x, y):
        return self.root(x) == self.root(y)
