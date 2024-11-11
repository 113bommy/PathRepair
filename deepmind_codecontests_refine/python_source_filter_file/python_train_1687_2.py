n = int(input())
a = [int(x) for x in input().split()]
m = 0
b = []
for i in range(n):
    m += a[i]
    if a[i] == 1:
        b.append(i)
ans = n * m
for i in range(2, m + 1):
    preans = 0
    if m % i != 0:
        continue
    c = 0
    for j in range(m):
        wg = (j // m) * m + m // 2
        if j != wg:
            preans += abs(b[wg] - b[j])
    ans = min(ans, preans)
if m == 1:
    ans = -1
print(ans)
