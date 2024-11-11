n = int(input())
a = [int(x) for x in input().split()]
a.sort()
xd = a[n - 1] - a[0]
yd = a[-1] - a[n]
ans = xd * yd
for i in range(n, 2 * n):
    xd = a[i] - a[i - n]
    yd = a[-1] - a[0]
    ans = min(ans, xd * yd)
print(ans)
