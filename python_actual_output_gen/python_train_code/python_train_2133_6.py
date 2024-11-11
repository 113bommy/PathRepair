l, d, v, g, r = map(int, input().split())
b = d / v
t = b % (g + r)
if t < g:
    print(t + (l - d) / v)
else:
    print(g + r + (l - d) / v)
