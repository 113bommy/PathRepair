#!/usr/bin/env python3
def ri():
    return map(int, input().split())

s, f, t = ri()

n = int(input())

if n == 0:
    print(s)
    exit()

i = list(ri())

p = 0
a = s
m = 10**100

for ii in i:
    if ii < f - t:
        if a - ii + 1 < m:
            m = a - ii + 1
            p = min(ii-1, a)
        a = max(a, ii) + t

if a <= f-t:
    p = a

print(p)
