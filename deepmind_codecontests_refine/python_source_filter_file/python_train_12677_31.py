from collections import deque
n,m,k=map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

a,b=[0],[0]
for i in range(n):
  a.append(a[i]+A[i])
for i in range(m):
  b.append(b[i]+B[i])
ans, j = 0,m
for i in range(N+1):
  if a[i]>k: break
  while b[j] > k-a[i]:
    j -= 1
  ans = max(ans,i+j)
print(ans)