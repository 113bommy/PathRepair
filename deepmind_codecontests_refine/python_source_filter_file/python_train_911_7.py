import sys
input = sys.stdin.readline
from collections import deque
n = int(input())
a = list(map(int,input().split()))
n += 2
ls = [0 for i in range(n*n)]
for i in range(n):
  for j in range(n):
    ls[i*n+j] = min(i,j,n-1-i,n-1-j)-1
ans = 0
st = [0]*(n*n)
for i in a:
  x,y = divmod(i-1,n-2)
  i = (x+1)*n+(y+1)
  ans += ls[i]
  st[i]=1
  q = deque([i])
  while q:
    j = q.popleft()
    for k in (j-n,j+n,j+1,j-1):
      if st[j]:
        if ls[j] < l[k]:
          ls[k] = ls[j]
          q.append(k)
      elif ls[j]+1 < ls[k]:
        ls[k] = ls[j]+1
        q.append(k)
print(ans)