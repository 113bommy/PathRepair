n, m, x = map(int, input().split())
ca = [list(map(int, input().split())) for _ in range(n)]
ans = 10**6
ok = False
for i in range(2**n):
    y = [0]*(m+1)
    for j in range(n):
        if i & (1 << j):
            for k in range(m+1):
                y[k] = y[k] + ca[j][k]
    if sum(z >= x for z in y[1:]) == m:
        ans = min(ans, y[0])
        ok = True
if ok:
    print(ans)
else:
    print(-1)
