import math

n,m=map(int,input().split())

while n!=0 and m!=0:
    if n>=2*m:
        n=n%m
        continue
    if m>=2*n:
        m=m%n
        continue
    else:
        break
    
print(n,m)