import math

a,b=map(int,input().split())

g=math.gcd(a,b)
ans=a*b//g
print(ans)