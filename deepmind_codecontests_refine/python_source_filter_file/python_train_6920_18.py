import sys
import math

n, m = [int(x) for x in (sys.stdin.readline()).split()]

if(n < m):
    if(n * 3 >= m):
        print(int((n + m) / 3))
    else:
        print(n)
else:
    if(m * 3 >= n):
        print(int((n + m) / 3))
    else:
        print(m)


        

