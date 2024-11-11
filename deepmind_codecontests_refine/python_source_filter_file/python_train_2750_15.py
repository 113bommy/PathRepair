import sys
import math

n = int(sys.stdin.readline())
l = [int(x) for x in (sys.stdin.readline()).split()]

l.sort()

c = l[0]
vmax = 1
cnt = 1
r = 1
for i in l[1:]:
    if(c == i):
        cnt += 1
    else:
        c = i
        r += 1
        if(cnt > vmax):
            vmax = cnt
            cnt = 0

if(cnt > vmax):
    vmax = cnt    
           
print(str(vmax) + " " + str(r))