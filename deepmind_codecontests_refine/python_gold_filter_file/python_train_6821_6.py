import random


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a, b):
    return (a * b) / gcd(a, b)


n,m,k = map(int, input().split())
r=[[0,0] for i in range(n)]
c=[[0,0] for i in range(m)]
for _ in range(k):
    x,w,v=map(int, input().split())
    if x==1:
        r[w-1][0]=_+1
        r[w-1][1]=v
    else:
        c[w - 1][0] = _+1
        c[w - 1][1] = v
for i in range(n):
    for j in range(m):
        if r[i][0]>=c[j][0]:
            print(r[i][1],end=' ')
        else:
            print(c[j][1],end=' ')
    print('')