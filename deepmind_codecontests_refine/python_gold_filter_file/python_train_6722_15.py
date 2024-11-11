import math
n = int(input())
a = int(math.floor(math.sqrt(n)))
while n % a != 0:
    a -= 1
print(a, n // a)