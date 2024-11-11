import math
a,b=map(int,input().split())
gcd=math.gcd(a,b)
ans=a*b//gcd
print(ans)