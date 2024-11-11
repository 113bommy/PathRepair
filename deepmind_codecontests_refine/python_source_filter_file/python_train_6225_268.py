import math
x, y = map(int, input())
print((x * y) // math.gcd(x, y))