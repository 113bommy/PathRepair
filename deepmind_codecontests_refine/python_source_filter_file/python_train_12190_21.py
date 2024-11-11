n, m = map(int, input().split())

maxf = (n - 1) * n // 2
if n & 1:
    t = (n - 1) // 2
    minf = t * (t + 1)
else:
    t = n // 2 - 1
    minf = t * (t + 1) + t + 1

ans = 0

for i in range(m):
    x, d = map(float, input().split())
    ans += x * n
    if d > 0:
        ans += maxf * d
    else:
        ans += minf * d
    # print(ans)

print("%.10f" % (ans / n))