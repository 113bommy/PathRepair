import math
a,b = map(int,input().split())
c = math.gcd(a,b)
print(int((a*b)/c))