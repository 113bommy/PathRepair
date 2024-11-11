import math

a, b = map(int, input().split())
x=a*b//(math.gcd(a,b))
print(x)