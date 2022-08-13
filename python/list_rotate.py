#2次元配列を90°回転
def rotate(l): #引数はリスト
    return list(zip(*l[::-1]))
