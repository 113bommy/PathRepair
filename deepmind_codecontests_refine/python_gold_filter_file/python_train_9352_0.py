def solve(K, ABs):
    if not ABs: return 0
    ansK = sum(b for a, b in ABs if (K | a) == K)
    pool = []
    for i in range(30, -1, -1):
        if (K & (1<<i)):
            pool.append(i)
    for p in pool:
        v = 1 << p
        KK = (K >> p) << p
        KKK = (K >> p)
        t = sum(b for a, b in ABs if (not(a & v) and (a | KK) >> p == KKK))
        if t > ansK: ansK = t
    return ansK
   

N, K = map(int, input().split())
ABs = []
for i in range(N):
    a, b = map(int, input().split())
    if a > K: continue
    ABs.append([a, b])

print(solve(K, ABs))