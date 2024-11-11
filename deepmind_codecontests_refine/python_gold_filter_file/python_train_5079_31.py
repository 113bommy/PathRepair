import bisect
n, d, a = map(int, input().split())
xh = [list(map(int, input().split())) for _ in range(n)]

xh.sort()
xs = [x for x, h in xh]

memo = [0 for _ in range(n)]

ans = 0

for j, (x, h) in enumerate(xh):
    memo[j] +=  memo[j-1]
    b = h - memo[j]
    if b > 0:
        c = (b + a - 1) // a
        memo[j] += c * a
        ans += c
        i = bisect.bisect_right(xs, x + 2 * d)
        if i < n:
            memo[i] -= c * a

print(ans)
