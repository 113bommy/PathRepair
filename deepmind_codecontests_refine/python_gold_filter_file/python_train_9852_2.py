import sys
import math

N, M, C = map(int, input().split())
mid = C // 2

res = []
for i in range(0, N):
   res.append(0)

l, r = 0, N - 1

for i in range(0, M):
   val = int(input())
   pos = 0
   if (val <= mid):
      for j in range(0, l + 1):
         if (res[j] == 0 or val < res[j]):
            res[j] = val
            pos = j
            break
      if (pos == l):
         l += 1
   else:
      for j in range(N - 1, r - 1, -1):
         if (res[j] == 0 or val > res[j]):
            res[j] = val
            pos = j
            break
      if (pos == r):
         r -= 1
   print ("%d" % (pos + 1))
   sys.stdout.flush()
   if (l > r):
      exit()
