#!/usr/bin/python3


t = int(input())
for z in range(t):
    n, g, p = input().split()
    n = int(n)
    g = int(g)
    p = int(p)
    if n % 2 == 0:
        good = n//2
    else:
        good = n//2 + 1
    if good > g:
        s = good//g
        _sum = s*(g+p)-p
        if good%g != 0:
            _sum += p + good%g
            s += 1
    else:
        _sum = n
    if _sum >= n:
        print(_sum)
    else:
        print(n)
    
    
