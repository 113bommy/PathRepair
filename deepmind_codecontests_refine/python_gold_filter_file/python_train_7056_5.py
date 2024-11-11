import sys
#input=sys.stdin.readline
from collections import deque

r=False
d=deque(list(input()))
for i in range(int(input())):
  Q=input().split()
  if Q[0]=='1':
    r=not r
  else:
    if (Q[1]=='1' and not r) or (Q[1]=='2' and r):
      d.appendleft(Q[2])
    else:
      d.append(Q[2])

if r:
  d.reverse()

print("".join(list(d)))
