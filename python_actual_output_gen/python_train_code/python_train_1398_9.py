N=int(input())
A=[int(input()) for _ in range(N)]

ans=0
for i in range(N):
  if A[i]==0:
    idx.append(i+1)
n=0
idx.append(N)
for iidx in idx:
  ans+=sum(A[n:iidx])//2
  n=iidx
print(ans)