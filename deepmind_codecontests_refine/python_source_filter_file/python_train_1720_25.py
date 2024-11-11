import sys
import math
input = sys.stdin.readline
n = int(input())
i = 0
while n >= 0:
  n -= i
  i += 1
print(n+i)