import math

n = int(input())
k = 0
while n % 3**k == 0:
    k += 1

print(n // k + 1)