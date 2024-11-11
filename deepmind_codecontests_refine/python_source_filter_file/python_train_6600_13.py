from math import gcd 
a,b,c,d = map(int,input().split())
p = abs(a*d-b*c)
if a/b>c/d:
    q=a*d
elif a/b<c/d:
    q=b*c
else:
    print(0)
    exit()
print(str(int(p/gcd(p,q)))+'/'+str(int(q/gcd(p,q))))