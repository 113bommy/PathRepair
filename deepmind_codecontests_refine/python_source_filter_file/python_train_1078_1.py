import math

n = int(input())
n -= 1
if n >= 3:
    print(10 ** n + 210 - (10 ** n) % 210)
else:
    print(-1)