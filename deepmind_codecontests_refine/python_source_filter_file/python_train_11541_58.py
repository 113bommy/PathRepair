a,b,c=map(int,input().split())
from math import gcd
print("NO")if c%gcd(a,b) else print("YES")