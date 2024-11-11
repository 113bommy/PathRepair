H, W = map(int, input().split())
c = [list(map(int, input().split())) for i in range(10)]
A = [list(map(int, input().split())) for i in range(H)]

for i in range(10):
    for j in range(10):
        for k in range(10):
            c[i][j] = min(c[i][j], c[i][k] + c[k][j])

ans = 0
for rA in A:
    for n in rA:
        if n >= 0:
            ans += c[n][1]

print(ans)