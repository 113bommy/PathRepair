from math import gcd
n, x = map(int,input().split())
p = list(map(lambda s: abs(s-x), list(map(int,input().split()))))
g = p[0]
for i in p:
    g = gcd(g, i)
print(g)
