import math
a,b = map(int, input().split())
x = math.gcd(a,b)
print((a*b)//x)