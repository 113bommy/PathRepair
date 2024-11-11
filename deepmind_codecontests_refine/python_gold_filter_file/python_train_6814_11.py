import math
n = int(input())
x = 81000000000000000000
inf = int(1e18)
l = n - x % n
r = inf + l - 1
print(l, r, sep=' ')
