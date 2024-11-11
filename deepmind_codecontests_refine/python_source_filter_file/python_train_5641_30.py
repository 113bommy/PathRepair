import math

t = int(input())
for i in range(t):
    b, p, f = (input().split())
    h, c = (input().split())
    b=int(b)
    p = int(p)
    f = int(f)
    h = int(h)
    c = int(c)

    s = 0
    if h < c: # p - is number of max pr, h - is max price
        p, f = f, p
        c, h = h, c
    while b > 1 and p > 0:
        d=min(p, b/2)
        s+=d * h
        p-=d
        b-=2*d
    while b > 1 and f > 0:
        d=int(min(f, b/2))
        s+=d * c
        f-=d
        b-=2*d
    print(int(s))