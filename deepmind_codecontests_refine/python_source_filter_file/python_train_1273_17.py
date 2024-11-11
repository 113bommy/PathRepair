import sys
from bisect import bisect_left
x0 = sys.stdin.readline()
n = int(x0)

x1 = sys.stdin.readline()
x2 = sys.stdin.readline()
l1 = [int(x) for x in x1.split(' ')]
l2 = [int(x) for x in x2.split(' ')]
l3 = [l1[i] - l2[i] for i in range(n)]
l3 = sorted(l3)
print(l3)
cnt = 0
for i in range(n):
   if l3[i] > 0:
       cnt += (i - bisect_left(l3, -l3[i] - 1))
print(cnt)

    