import math

x = int(input())
y = 360

lcm = x * y // math.gcd(x, y)
print(lcm/x)