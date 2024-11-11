import sys
import math
  
n, k = [int(x) for x in (sys.stdin.readline()).split()]

for i in range(n):
    t = []
    for j in range(n):
        if(j == i):
            t.append(str(k))
        else:
            t.append(str(0))
            
    print(" ".join(t))