l, d, v, g, r = map(int, input ().split ())
s = (d / v) % (g + r)
print(l / v + (s > g) * (g + r - s))