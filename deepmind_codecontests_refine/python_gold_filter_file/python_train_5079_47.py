from bisect import bisect_right

n, d, a = map(int, input().split())
xh = sorted(list(map(int, input().split())) for _ in range(n))
x = [0] * (n + 1)
h = [0] * (n + 1)
s = [0] * (n + 1)

for i, (f, g) in enumerate(xh):
    x[i], h[i] = f, g
x[n] = 10 ** 10 + 1
ans = 0
for i in range(n):
    if i > 0:
        s[i] += s[i - 1]
    h[i] -= s[i]
    if h[i] > 0:
        num = 0 - - h[i] // a
        ans += num
        s[i] += num * a

        j = bisect_right(x, x[i] + d * 2)
        s[j] -= num * a
print(ans)
