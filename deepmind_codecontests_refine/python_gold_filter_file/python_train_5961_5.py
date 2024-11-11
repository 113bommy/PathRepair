from math import *

def rr(t):
    zzz = [t(i) for i in input().split()]
    if len(zzz) == 1:
        return zzz[0]
    return zzz

def r3(t):
    return [t(i) for i in input()]

n = int(input())
cp = 1
print(4 + n*3)
cp = 1
print(cp, 1)
print(cp, 2)
print(cp - 1, 2)
print(cp - 1, 1)
print(cp, 0)
print(cp + 1, 0)
print(cp + 1, 1)
cx = 2
cy = 0
for i in range(n - 1):
    print(cx, cy - 1)
    print(cx + 1, cy)
    print(cx + 1, cy - 1)
    cx += 1
    cy -= 1
    
