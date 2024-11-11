#!/usr/bin/env python3
n, k = map(int, input().split())
x = 2*k+1
r = (n - 1) // x + 1
d = r*k - n
s = min(1, k+1-d)
print(r)
print(' '.join([str(s+x*i) for i in range(r)]))
