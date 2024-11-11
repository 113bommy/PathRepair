from collections import deque
n,k = map(int,input().split())
a = list(map(int,input().split()))
k -= 1
mnlist = []
q = deque([0])
for i in range(1,k):
  while q:
    x = q.pop()
    if a[i]>a[x]:
      q.append(x)
      q.append(i)
      break
  if not q:
    q.append(i)

for i in range(k,n+1):
  t = q.popleft()
  mnlist.append(a[t])
  if t != i-k:
    q.appendleft(t)
  if i == n:
    break
  while q:
    x = q.pop()
    if a[i]>a[x]:
      q.append(x)
      q.append(i)
      break
  if not q:
    q.append(i)
mxlist = []
q = deque([0])
for i in range(1,k):
  while q:
    x = q.pop()
    if a[i]<a[x]:
      q.append(x)
      q.append(i)
      break
  if not q:
    q.append(i)

for i in range(k,n+1):
  t = q.popleft()
  mxlist.append(a[t])
  if t != i-k:
    q.appendleft(t)
  if i == n:
    break
  while q:
    x = q.pop()
    if a[i]<a[x]:
      q.append(x)
      q.append(i)
      break
  if not q:
    q.append(i)
ans = n-k
r = set()
for i in range(1,n-k):
  if a[i-1]<mnlist[i] and mxlist[i]<a[i+k]:
    r.add(i)
flg = 0
flg2 = 0
for i in range(1,n-k):
  if a[i-1] < a[i]:
    flg += 1
  else:
    flg = 0
  if flg >= k:
    r.add(i-k)
    flg2 = 1
print(ans-len(r)+flg2)