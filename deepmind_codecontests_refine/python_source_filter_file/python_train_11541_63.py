import math
a,b,c=map(int,input().split())
d=math.gcd(a,b)

if c%d==0:
    print("YES")
else:
    print("NO")
