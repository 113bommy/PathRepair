ka, kb = 0, 0

def g(a, b):
    global ka, kb
    if a == b:
        return
    if abs(a - b) == 2:
        if a == 1:
            ka += 1
        else:
            kb += 1
    else:
        if a > b:
            ka += 1
        else:
            kb += 1

def main():
    global ka, kb
    k, a, b = map(int, input().split())
    aa = [[] for i in [1, 1, 1]]
    bb = [[] for i in [1, 1, 1]]
    aa[0] = list(map(int, input().split()))
    aa[1] = list(map(int, input().split()))
    aa[2] = list(map(int, input().split()))
    bb[0] = list(map(int, input().split()))
    bb[1] = list(map(int, input().split()))
    bb[2] = list(map(int, input().split()))
    x = a
    y = b
    o = 1
    c = [[x, y]]
    d = [[0, 0]]
    g(x, y)
    if o == 1:
        return
    x, y = aa[x - 1][y - 1], bb[x - 1][y - 1]
    #print(x, y, ka, kb)
    while [x, y] not in c:
        o += 1
        c += [[x, y]]
        d += [[ka, kb]]
        g(x, y)
        x, y = aa[x - 1][y - 1], bb[x - 1][y - 1]
        #print(x, y, ka, kb)
        if o == k:
            return
    ind = c.index([x, y])
    dka = ka - d[ind][0]
    dkb = kb - d[ind][1]
    delta = o - ind
    kk = (k - ind) // delta - 1
    #print(dka, dkb, delta)
    ka += kk * dka
    kb += kk * dkb
    o += kk * delta
    while o != k:
        o += 1
        g(x, y)
        x, y = aa[x - 1][y - 1], bb[x - 1][y - 1]
        #print(x, y, ka, kb)

main()
print(ka, kb)
