#!/usr/bin/env python3

n = int(input().strip())
ais = list(map(int, input().strip().split()))

ais.sort()

bis = [(ais[i] - ais[i-1]) for i in range(1, n)]

m = min(bis)

v = bis.count(m)


print (v)
