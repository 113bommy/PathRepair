import sys
import os

n,m = map(float, sys.stdin.readline().split())

res = 0
if (n == 1 or m ==1):
    res = 1
else:
    res = (1+(n-1)*(m-1)/(n*m-1))/n
print(res)