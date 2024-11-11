from math import gcd
p,q = map(int,input().split())
n = int(input())
t = [*map(int,input().split())]
d = gcd(p,q)
p/=d
q/=d
a=int(1)
b=int(t[-1])
i=n-2
while i>=0 :
    a=b*t[i]+a
    d = gcd(a,b)
    a/=d
    b/=d
    i-=1
    c=a
    a=b
    b=c
if a==p and q==b :
    print("YES")
else :
    print("NO")