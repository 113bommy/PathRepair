n = int(input())
C = [int(i) for i in input().split()]
inf = sum(C) * 2
ans = inf
a, b = 0, C[0]
prev = input()
rprev = prev[::-1]
for i in range(1, n):
    cur = input()
    rcur = cur[::-1]
    p, q, r, s = inf, inf, inf, inf
    if prev <= cur:
        p = a
    if prev <= rcur:
        q = a + C[i]
    if rprev <= cur:
        r = b
    if rprev <= rcur:
        s = b + C[i]
    a = min(p, r)
    b = min(q, s)
    prev = cur
    rprev = rcur

ans = min(a, b)
if ans == inf:
    print(-1)
else:
    print(ans)
