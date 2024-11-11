import math
import sys

n = int(input())
a = []
b = [None] * n
c = [None] * n

for x in input().split():
    a.append(int(x))
for i in range(0, n - 1):
    b[i] = c[i] = abs(a[i + 1] - a[i])
    b[i] *= math.pow(-1, i)
    c[i] *= math.pow(-1, i + 1)

maxCurrB = b[0]
maxB = b[0]
maxCurrC = c[0]
maxC = c[0]

for i in range (1, n - 1):
    maxCurrB = max(b[i], maxCurrB + b[i])
    maxB = max(maxB, maxCurrB)
    maxCurrC = max(c[i], maxCurrC + c[i])
    maxC = max(maxC, maxCurrC)

print(max(maxB, maxC))

