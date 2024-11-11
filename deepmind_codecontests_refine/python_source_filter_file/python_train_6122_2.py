N, = map(int, input().split())
X = list(map(int, input().split()))
r = 0
for d in range(1, N):
    s = 0
    vs = set([0, N-1])
    for ld in range(d, N, d):
        bld = N-ld-1
        vs.add(bld)
        if ld in vs:
            break
        vs.add(ld)
        s += X[ld] + X[bld]
        r = max(s, r)
print(r)
