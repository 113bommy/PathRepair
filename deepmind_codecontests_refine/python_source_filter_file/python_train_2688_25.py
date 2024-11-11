from math import *
a,b=map(int,input().split())
s=input()
t=input()
g=gcd(a,b)
for i in range(g):
    if s[a//g*i]!=t[b//g*i]:
        print(-1)
        exit()
print(a*b*g)