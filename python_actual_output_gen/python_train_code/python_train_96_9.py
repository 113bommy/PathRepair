n, k, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
s = sum(a)

maximum = 0
i = 0
while i < n and i * s <= m:
    cur = m - s * i
    ans = (k + 1) * i
    for pos in range(k):
        if cur < a[pos]:
            break
        c = min(n - i, cur // a[pos])
        cur -= a[pos] * c
        ans += c
    maximum = max(maximum, ans)
    i += 1

print(maximum)
