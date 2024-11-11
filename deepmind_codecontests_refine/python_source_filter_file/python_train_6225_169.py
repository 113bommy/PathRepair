import math
a, b = map(int, input().split())
p = math.gcd(a, b)
print(b * (a // p))
