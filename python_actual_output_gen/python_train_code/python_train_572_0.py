n, l, r, p, q = map(int, input().split())
arr = [0] + list(map(int, input().split()))
res, s, d = int(1<<62), sum(arr), 0
for i in range(n+1):
    if i > 0:
        d += arr[i-1]
    t = d * l + (s - d) * r
    j = n - i
    if i > j:
        t += (i - j - 1) * p
    if i < j:
        t += (j - i - 1) * q
    res = min(res, t)
print(res)
