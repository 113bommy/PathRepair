from math import gcd
a,b,c,d=map(int,input().split())
f=b//c - (a-1)//c
g=b//d - (a-1)//d
k=c*d//gcd(c,d)
h=f+g-(b//k-(a-1)//k)
print((b+1-a)-h)