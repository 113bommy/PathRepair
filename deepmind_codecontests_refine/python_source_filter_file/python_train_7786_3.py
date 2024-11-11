import math
s = int(input())
e = 1000000000
x = (s - s % e) % e
print(0, 0, e, 1, x, (s + x) // e)