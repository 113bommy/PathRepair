import math
import cmath

s = input()
n = i = t = e = 0
for a in s:
    if a == 'n': n += 1
    if a == 'i': i += 1
    if a == 't': t += 1
    if a == 'e': e += 1
print(max(0, min((n-1)//2, e//3, i, t)))

