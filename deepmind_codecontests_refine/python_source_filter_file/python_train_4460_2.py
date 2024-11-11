from collections import deque
N=int(input())
As=[int(i) for i in input().split()]
neg_odd,neg_even=deque([]),deque([])
S_odd,S_even=0,0
for i,A in enumerate(As):
  if i%2==0:
    if A>=0:
      S_even+=A
    else:
      neg_even.append(i)
  if i%2==1:
    if A>=0:
      S_odd+=A
    else:
      neg_odd.append(i)
ans=[]
A_size=N
if S_odd==S_even==0:
  a=max(As)
  print(a)
  i=0
  while As[i]!=a:
    ans.append(1)
    i+=1
    A_size-=1
  while A_size>1:
    ans.append(A_size)
    A_size-=1
elif S_odd<=S_even:
  print(S_even)
  if N%2==0:
    ans.append(N)
    A_size-=1
  if neg_even:
    t=0
    while A_size-1==neg_even[-1]:
      neg_even.pop()
      ans.append(A_size)
      ans.append(A_size-1)
      A_size-=2
      if not neg_even:
        break
    if neg_even:
      while t==neg_even[0]:
        neg_even.popleft()
        ans.append(1)
        ans.append(1)
        t+=2
        A_size-=2
        if not neg_even:
          break
    for a in neg_even:
      ans.append(a+1-t)
      A_size-=2
      t+=2
  while A_size>1:
    ans.append(2)
    A_size-=2
else:
  print(S_odd)
  if N%2==1:
    ans.append(N)
    A_size-=1
  ans.append(1)
  A_size-=1
  if neg_odd:
    t=1
    while A_size==neg_odd[-1]:
      neg_odd.pop()
      ans.append(A_size)
      ans.append(A_size-1)
      A_size-=2
      if not neg_odd:
        break
    if neg_odd:
      while t==neg_odd[0]:
        neg_odd.popleft()
        ans.append(1)
        ans.append(1)
        t+=2
        A_size-=2
        if not neg_odd:
          break
    for a in neg_odd:
      ans.append(a-t)
      A_size-=2
      t+=2
  while A_size>1:
    ans.append(2)
    A_size-=2
print(len(ans))
for a in ans:
  print(a)