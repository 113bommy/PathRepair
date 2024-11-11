N, = map(int, input().split())
X = list(map(int, input().split()))
t = 0
for x in X:
    t = t^x
inf = float('inf')
d = dict()
def it(x, y, z):
    if (x, y, z) in d:
        return d[(x, y, z)]
    xm, ym, zm = x%2, y%2, z%2
    if xm ^ ym != zm:
        d[(x, y, z)] = inf
        return inf
    if x^y == z:
        d[(x, y, z)] = 0
        return 0
    Rz = 2*it(x>>1, y>>1, z>>1)
    Ro = inf
    if x:
        Ro = 2*it((x-1)>>1, (y+1)>>1, z>>1)+1
    Rz = min(Rz, Ro)
    d[(x, y, z)] = Rz
    return Rz

r = it(X[0], X[1], t^X[0]^X[1])
if 0 < r < 10**18:
    print(r)
else:
    print(-1)
