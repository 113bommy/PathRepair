# coding: utf-8

from bisect import bisect, bisect_left
from random import random
import io, os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, q = map(int, input().split())
a = list(map(int, input().split()))
v = [list() for i in range(n + 1)]

for i in range(n):
  v[a[i]].append(i + 1)
  
for i in range(q):
  l, r = map(int, input().split())
  l -= 1
  r -= 1
  ans = 1
  s = set()
  
  for j in range(25):
    idx = int(random() * (r - l + 1)) + l
    
    if a[idx] in s:
      continue
    
    s.add(a[idx])
    
    if len(v[a[idx]]) <= (r - l + 2) // 2:
      continue
    
    left = bisect_left(v[a[idx]], l)
    right = bisect(v[a[idx]], r + 1)
    
    if right - left > (r - l + 2) // 2:
      ans = 2 * (right - left) - (r - l + 1)
      break
    
  print(ans)