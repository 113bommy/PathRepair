import math as m
n=int(input())
a=input().split()
b=1
for i in a:
    i=int(i)
    b*=i//m.gcd(b,i)
    
print(sum(b//int(i) for i in a)%(10**9+7)) 
