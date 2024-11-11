n, mod = map(int, input().split())
a = list(map(int, input().split()))
if mod <= n:
    print(0)
    exit()
ret = 1
for i in range(n - 1):
    for j in range(i + 1, n):
        ret *= abs(a[i] - a[j])
        ret %= mod
print(ret)