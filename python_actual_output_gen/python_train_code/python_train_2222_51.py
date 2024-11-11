_, __, *d = map(int, open(0).read().split())
print(min(d[1::2]) - max(d[::2]) + 1)