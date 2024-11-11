from collections import deque
import bisect
N=int(input())
L=deque()
for i in range(N):
  s=int(input())
  if i==0:
    L.append(s)
  else:
    if s<=L[0]:
      L.appendleft(s)
    else:
      L[bisect.bisect(L,s)-1]=s
print(len(L))