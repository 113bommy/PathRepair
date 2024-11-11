n, m, k = map(int, input().split())
P = list(map(int, input().split()))
L = [list(map(int, input().split())) for _ in range(n)]
r = 0
for i in range(n):
    for j in range(m):
        e = P.index(L[i][j])
        r += e
        P = [L[i][j]]+P[:e]+P[e+1:]
print(r)
