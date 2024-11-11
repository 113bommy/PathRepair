N,K,*A = map(int, open(0).read().split())
Ap = []
An = []
Az = []
for c in A:
  if c>0:
    Ap.append(c)
  elif c<0:
    An.append(c)
  else:
    Az.append(c)
l = -10**20
r = 10**20
Ap.sort(reverse=True)
An.sort()
while l+1<r:
  s = (l+r)//2
  cnt = 0
  j = len(Ap)-1
  for i in range(len(Ap)):
    while j>-1 and Ap[i]*Ap[j]<s:
      j -= 1
    cnt += len(Ap)-1-j
  for i in range(len(Ap)):
    if Ap[i]*Ap[i]<s:
      cnt -= 1
  j = len(An)-1
  for i in range(len(An)):
    while j>-1 and An[i]*An[j]<s:
      j -= 1
    cnt += len(An)-1-j
  for i in range(len(An)):
    if An[i]*An[i]<s:
      cnt -= 1
  cnt //= 2
  if s>0:
    cnt += len(Az)*(len(Az)-1)//2 + len(Az)*(len(Ap)+len(An)) + len(Ap)*len(An)
  else:
    j = 0
    for i in range(len(Ap)-1,-1,-1):
      while j<len(An) and Ap[i]*An[j]<s:
        j += 1
      cnt += j
  if cnt>=K:
    r = s
  else:
    l = s
print(l)