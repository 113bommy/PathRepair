import bisect
n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

a_cum = [0 for _ in range(n+1)]
for i in range(n):
    a_cum[i+1] = a_cum[i] + a[i]

l, r = 0, 10 ** 6
while r - l > 1:
    x = (l + r) // 2
    cnt = 0

    for i in range(n):
        idx = bisect.bisect_left(a, x-a[i])
        cnt += n - idx

    if cnt >= m:
        l = x

    else:
        r = x

ans = 0
cnt = 0
for i in range(n):
    idx = bisect.bisect_left(a, l-a[i])
    cnt += n - idx
    ans += a_cum[n] - a_cum[idx]
    ans += a[i] * (n - idx)

if cnt > m:
    ans -= a[i] * (cnt - m)

print(ans)