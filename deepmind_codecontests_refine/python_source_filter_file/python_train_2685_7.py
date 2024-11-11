N,M = map(int,input().split())
A = list(map(int,input().split()))
s = set()
B = []
for a in A:
    t = a & -a
    s.add(t)
    if len(s) > 1:
        print(0)
        exit()
    B.append(a // t)

from math import gcd
l = 1
for b in B:
    l = b*l // gcd(b,l)

x = l*t // 2
ans = M//x - M//(2*x)
print(ans)