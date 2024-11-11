import math


n = int(input())
m = int(input())

x = math.log(m, 2)
if x >= n:
    print(m % (2 ** n))
else:
    print(m)
