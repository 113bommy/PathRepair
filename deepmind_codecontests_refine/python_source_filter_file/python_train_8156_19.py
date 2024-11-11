import sys
import math
 
x, y, a, b = [int(x) for x in (sys.stdin.readline()).split()]

res = []
for j in range(x, a, -1):
    for i in range(min(j - 1, y), b - 1, -1):
        res.append((j, i))

print(len(res))
for i in res[::-1]:
    print(i[0], i[1])