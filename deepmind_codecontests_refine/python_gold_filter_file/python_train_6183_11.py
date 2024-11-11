l, d, v, g, r = map(int, input().split())
b = d / v
t = b % (g + r)
if t < g:
    print(b + (l - d) / v)
else:
    print(b - t + g + r + (l - d) / v)
