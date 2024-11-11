n, m, h = map(int, input().split())
frnt = list(map(int, input().split()))
lft = list(map(int, input().split()))
res = []
for i in range(n):
    row = list(map(int, input().split()))
    resr = []
    for j in range(m):
        if row[j]==1:
            resr.append(max(lft[i], frnt[j]))
        else:
            resr.append(0)
    res.append(resr)

for i in range(n):
    print(*res[i])

            


