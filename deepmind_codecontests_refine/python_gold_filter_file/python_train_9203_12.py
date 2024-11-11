import sys
import math

n = int(sys.stdin.readline())

for i in range(4):
    a, b, c, d = [int(x) for x in (sys.stdin.readline()).split()]
    v1 = min(a, b)
    v2 = min(c, d)
    if(n - v1 >= v2):
        print(str(i + 1) + " " + str(v1) + " " + str(n - v1))
        exit()
        
print(-1)