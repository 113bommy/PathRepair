import math
n = int(input())
x = int(math.floor(math.sqrt(n)))
while n % x != 0:
    x += 1
print(x, n // x)