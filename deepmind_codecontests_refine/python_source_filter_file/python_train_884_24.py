import math as ma

n=int(input())
a=int(input())
b=int(input())
c=int(input())
if a<=b-c:
    print(n//a)
else:
    d=(n-b)//(b-c)+1
    n=n-d*(b-c)
    d+=n//a
    print(max(max(d,0),n//a))