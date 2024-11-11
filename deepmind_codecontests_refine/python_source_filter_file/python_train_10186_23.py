import itertools
n, m, r = map(int, input().split())
t = list(map(int, input().split()))
t.sort()
d = [[10 * 18]*n for j in range(n)]
for i in range(n):
    d[i][i] = 0

for i in range(m):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    d[a][b] = c
    d[b][a] = c

for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])


ans = 10**18
for p in itertools.permutations(t):
    now = 0
    for i in range(r-1):
        now += d[p[i]-1][p[i + 1]-1]
    ans = min(ans, now)
print(ans)
