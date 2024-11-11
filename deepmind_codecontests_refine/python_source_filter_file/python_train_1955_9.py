n = int(input())
a = [round(float(input()) * 10**9) for _ in range(n)]
cs = [[0] * 20 for _ in range(20)]

dc = []
for i in a:
    x = 0
    for _ in range(19):
        if i % 2 == 0:
            i //= 2
            x += 1
    y = 0
    for _ in range(19):
        if i % 5 == 0:
            i //= 5
            y += 1

    cs[18-x][18-y] += 1
    dc.append((x, y))
for i in range(20):
    for j in range(19):
        cs[i][j+1] += cs[i][j]
for i in range(20):
    for j in range(19):
        cs[j+1][i] += cs[j][i]


ans = 0
for x, y in dc:
    ans += cs[x][y]
for i in a:
    if i % 10**9 == 0:
        ans -= 1
ans //= 2

print(ans)
