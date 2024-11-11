#TLE
K,Q = map(int,input().split())
D = list(map(int,input().split()))
NXM = [tuple(map(int,input().split())) for i in range(Q)]

for N,X,M in NXM:
    ds = [d%M for d in D]
    a,b = divmod(N-1,K)
    s = 0
    z = 0
    for i,d in enumerate(ds):
        if i==b:
            sb = s
            zb = z
        if d==0:
            z += 1
        s += d
    x = (X + s*a + sb)//M - X//M
    y = z*a + zb
    print(N-1-x-y)