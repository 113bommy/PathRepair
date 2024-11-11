def f(x, m):
    if x < m:
        return (m, x)
    else:
        return (m * 2 - x, m)

n = int(input())
d = {0 : [0]}
for i in range(n):
    x, y = map(int, input().split())
    m = max(x, y)
    if m in d:
        if x == m:
            d[m].append(y)
        else:
            d[m].append(m * 2 - x)
    else:
        if x == m:
            d[m] = [y]
        else:
            d[m] = [m * 2 - x]
t = sorted(d.keys())
ans = 0
for k in t:
    d[k].sort()
    ans += d[k][-1] - d[k][0]
dp1 = [0] * len(t)
dp2 = [0] * len(t)
for i in range(len(t) - 1):
    k = t[i]
    k2 = t[i + 1]
    x11, y11 = f(d[k][0], k)
    x12, y12 = f(d[k][-1], k)
    x21, y21 = f(d[k2][0], k + 1)
    x22, y22 = f(d[k2][-1], k + 1)
    dp1[i + 1] = min(dp1[i] + abs(x11 - x22) + abs(y11 - y22), dp2[i] + abs(x12 - x22) + abs(y12 - y22))
    dp2[i + 1] = min(dp1[i] + abs(x11 - x21) + abs(y11 - y21), dp2[i] + abs(x12 - x21) + abs(y12 - y21))
print(min(dp1[-1], dp2[-1]) + ans)