import sys
input = sys.stdin.readline
from collections import deque
t = int(input())
for _ in range(t):
  a = input().rstrip()
  n = len(a)
  even = deque()
  odd = deque()
  for i in range(n):
    if int(a[i])%2:
      odd.append(int(a[i]))
    else:
      even.append(int(a[i]))
  ans = []
  while even and odd:
    e = even.pop()
    o = odd.pop()
    if e > o:
      ans.append(o)
      even.appendleft(e)
    else:
      ans.append(e)
      odd.appendleft(o)
  if even:
    ans.extend(even)
  elif odd:
    ans.extend(odd)
  print(*ans,sep="")