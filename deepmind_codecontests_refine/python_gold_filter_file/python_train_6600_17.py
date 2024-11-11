a,b,c,d = map(int, input().split())

b*=c
d*=a

a = abs(b-d)
b = max(b, d)

import math

div = math.gcd(a,b)

print(a//div, "/", b//div, sep="")