N,M=map(int, input().split())
A=[]
for i in range(N):
  d=list(map(int, input().split()))
  A.append(d)
S=[1]*M
num=[0]*N
ans=N
for i in range(M):
  cnt=[0]*M
  for j in range(N):
    d=A[j][num[j]]
    while S[d-1]==0:
      num[j]+=1
      d=A[j][num[j]]
    cnt[d-1]+=1
  e=max(cnt)
  ans=min(e,ans)
  f=cnt.index(e)
  S[f]=0
print(ans)
