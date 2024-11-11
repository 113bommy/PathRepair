n = int(input())
a = list(map(lambda i: input(), range(n)))

m = 13

for i in range(n):
    for j in range(i + 1, n):
        m = min(m, sum(a[i][k] != a[j][k] for k in range(6)))

print((m - 1) // 2)
