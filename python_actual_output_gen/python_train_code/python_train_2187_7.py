N, K =map(int, input().split())

A = list(map(int, input().split()))

mod=10**9 +7
count=0
for i in range(N):
  for j in range(i+1, N):
    if A[i]>A[j]:
      count+=K
  for k in range(N):
    if A[i]>A[k]:
      count+=(K-1)*K/2 % mod
  

print(int(count%mod))