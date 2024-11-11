import sys
import math

n = int(sys.stdin.readline())
an = [int(x) for x in (sys.stdin.readline()).split()]

t = list(an)
t.sort()

c = 0
for i in range(2):
    if(t[i] != an[i]):
        c += 1
        
if(c <= 1):
    print("YES")
else:
    print("NO")
    