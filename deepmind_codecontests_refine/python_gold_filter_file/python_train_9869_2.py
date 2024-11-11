from fractions import gcd
from math import ceil,sqrt
a, b = map(int, input().split())

g = gcd(a,b)
# print(g)
s = set()
for i in range(2,ceil(sqrt(g))+1):
    while g % i == 0:
        g //= i
        s.add(i)
if g != 1:
    s.add(g)
# print(g)
# print(s)
print(len(s)+1)
