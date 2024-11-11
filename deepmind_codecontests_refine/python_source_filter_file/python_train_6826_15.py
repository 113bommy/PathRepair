import sys
import math
 
n = int(input())

vmax = 0
res = ""
for i in range(n):
    st = (sys.stdin.readline()).split()
    vsum = int(st[1]) * 100 - int(st[2]) * 50 + sum(map(int, st[3:]))
    if(vsum > vmax):
        vmax = vsum
        res = st[0]

print(res)
