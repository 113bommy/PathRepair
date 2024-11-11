import math

A, B, C = map(int, input().split())

y = math.sqrt((A*B)/C)

x = A/y
z = C/y
print(int(x*4 + y*4 + z*4))