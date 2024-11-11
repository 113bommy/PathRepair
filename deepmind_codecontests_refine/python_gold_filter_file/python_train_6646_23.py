n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
ans = 3000
t = [True] * m
for _ in range(m):
    p = [0] * m
    for i in range(n):
        for x in a[i]:
            if t[x - 1]:
                p[x - 1] += 1
                break
    ma = max(p)
    ans = min(ans, ma)
    t[p.index(ma)] = False
print(ans)
