n, k = map(int, input().split())

if k <= n:
    res = (k - 1) // 2
elif k // 2 <= n:
    res = n - k // 2
else:
    res = 0

print(res)
