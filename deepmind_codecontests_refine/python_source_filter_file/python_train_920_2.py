n, x = map(int, input().split())
a = list(map(int, input().split()))
d = a.copy()
ans = float('inf')
for i in range(n):
    ans = min(ans, sum(d) + x * i)
    for j in range(n):
        d[j] = min(d[j], a[(j - (i + 1) + n) % n])
print(ans)