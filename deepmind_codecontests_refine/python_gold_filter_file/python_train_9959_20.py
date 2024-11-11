n, w = map(int, input().split())
a = [int(i) for i in input().split()]
res = [0] * (n + 1)
for i in range(n):
    res[i] = a[i]
    res[i] += res[i - 1]
r = w
l = 0
for i in range(n):
    r = min(r, w - res[i])
    l = max(l, -res[i])
print(max(r - l + 1, 0))