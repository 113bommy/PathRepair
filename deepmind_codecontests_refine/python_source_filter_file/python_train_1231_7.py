#!/usr/bin/env python3
n, h, *d = map(int, open(0).read().split())
a = max(d[::2])
b = sorted(b for b in d[1::2] if b >= a)
i = 0
for b in b:
    h -= b
    i += 1
    if h <= 0:
        print(i)
        exit()
print(i + 0--h // a)