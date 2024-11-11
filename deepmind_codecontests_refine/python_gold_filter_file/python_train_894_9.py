import math
n=int(input())
a,b=n//2,n-n//2
while math.gcd(a,b)!=1:
    a-=1
    b+=1
print(a,b)
