N, C, K, *T = map(int, open(0).read().split())
T.sort()

ans = 1
curm = T[0]
curc = 0
for t in T:
    curc += 1
    if t > curm+K or curc == C:
        ans += 1
        curm = t
        curc = 1

print(ans)
