n, D = map(int, input().split())
l = [list(map(int, input().split())) for _ in range(n)]
res = 0
for i in range(n):
    for j in range(i + 1, n):
        d = sum((l[i][k] - l[j][k]) ** 2 for k in range(D))
        if int(d ** 0.5) ** 2 == d:
            res += 1
print(res)