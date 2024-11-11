import math
a, b = list(map(int,input().split()))
g = math.gcd(a, b)
print(a * b // g)