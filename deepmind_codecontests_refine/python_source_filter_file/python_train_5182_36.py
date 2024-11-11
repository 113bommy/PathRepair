N, K = list(map(int, input().split()))
P = list(map(int, input().split()))
C = list(map(int, input().split()))

P = list(map(lambda x:x-1, P))

ans = -float('inf')
for si in range(N):
    s = []
    tot = 0
    x = si
    while True:
        x = P[x]
        s.append(C[x])
        tot += C[x]
        if x==si:
            break
    l = len(s)
    now = 0
    t = 0
    for i in range(l):
        if i+1 > K: break
        t += s[i]
        now = t
        if tot >0:
            e = (K-(i+1))//l
            now += tot * e
        ans = max(ans, now)


print(ans)


