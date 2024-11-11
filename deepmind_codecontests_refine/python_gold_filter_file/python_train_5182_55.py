N,K = map(int,input().split())
P = [int(t) - 1 for t in input().split()]
C = list(map(int,input().split()))

ans = -1e18
for si in range(N):
    x = si
    s = []
    tot = 0
    while True:
        x = P[x]
        s.append(C[x])
        tot += C[x]
        if x == si:
            break
    l = len(s)
    t = 0
    for i in range(l):
        t += s[i]
        if i+1 > K:
            break
        now = t
        if tot > 0:
            e = (K-(i+1))//l
            now += tot*e
        if ans < now:
            ans = now
print(ans)