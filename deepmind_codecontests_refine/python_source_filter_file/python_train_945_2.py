#!/usr/bin/python
import sys
import math
def gcd(a, b):
    if a == 0: 
        return b
    return gcd(b % a, a)

N = int(input())
x, y = map(int, input().split(' '))
divisor = 2
result = []
while divisor < math.sqrt(max(x,y)):
    if (x % divisor == 0) or (y % divisor == 0):
        result.append(divisor)
        while x % divisor == 0:
            x /= divisor
        while y % divisor == 0:
            y /= divisor
    divisor += 1
if (x > 1):
    result.append(x)    
if (y > 1):
    result.append(y)
for i in range(1, N):
    x, y = map(int, input().split(' '))
    new_result = [i for i in result if ((x % i == 0) or (y % i == 0))]
    result = new_result
if len(result) < 1:
    print(-1)
else:
    print(int(result[0]))
