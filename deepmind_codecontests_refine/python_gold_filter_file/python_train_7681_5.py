n,k=map(int,input().split())
P=[int(i) for i in input().split()]
import collections
from collections import deque
M1,M2=deque(),deque()
A1,A2=[],[]
M1.append(0)
for i in range(1,n):
  while M1:
    if P[M1[-1]]>P[i]:
      M1.pop()
    else:
      M1.append(i)
      break
  if not M1:
    M1.append(i)
  if M1[0]==i-k-1:
    M1.popleft()
  if i<k:
    continue
  else:
    A1.append(P[M1[0]])
M2.append(0)
for i in range(1,n):
  while M2:
    if P[M2[-1]]<P[i]:
      M2.pop()
    else:
      M2.append(i)
      break
  if not M2:
    M2.append(i)
  if M2[0]==i-k-1:
    M2.popleft()
  if i<k:
    continue
  else:
    A2.append(P[M2[0]])
ans=1
for i in range(n-k):
  if A1[i]==P[i] and A2[i]==P[i+k]:
    continue
  else:
    ans+=1
Q=[0]*n
for i in range(1,n):
  if P[i]>P[i-1]:
    Q[i]=Q[i-1]+1
  else:
    continue
count=0
for i in range(n):
  if Q[i]==k-1:
    count+=1
print(ans-max(0,count-1))