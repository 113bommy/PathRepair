import math
from fractions import gcd
def lcm(X,Y):
        return (X*Y) // gcd(X,Y)
x, y, a, b = map(int, input().split())
xy = lcm(x,y)

c = 0
for i in range(a, b):
        if i%xy == 0:
                c = i//xy
                break
d = 0

for i in range(b,a-1,-1):
        if i%xy == 0:
                d = i//xy
                break
if d-c == 0 and d == 0:
        print (0)
else:
        ans = d-c+1
        print (ans)