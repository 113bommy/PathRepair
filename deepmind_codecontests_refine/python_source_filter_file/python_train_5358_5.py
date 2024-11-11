#!/usr/bin/env python3

a = int(input())
b = int(input())
n = a + b + 1
res = [x+1 for x in range(n - a, n)] + [x for x in range(n - a, 0, -1)]
print(*res)
