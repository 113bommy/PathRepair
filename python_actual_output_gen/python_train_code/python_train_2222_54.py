_, __, *d = map(int, open(0).read().split())
print(max(min(d[1::2]) - max(d[::2]) + 1), 0)