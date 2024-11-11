N,K=map(int,input().split())
AL=list(map(int,input().split()))
summ=0
for i in range(N):
  summ+=AL[i]
candidate=set()
for i in range(1,int(summ**0.5)+1):
  if summ%i==0:
    candidate.add(i)
    candidate.add(summ/i)
ans=0
for x in candidate:
  need=0
  r=[0]*N
  for i in range(N):
    r[i]=AL[i]%x
  sorted(r)
  rsum=0
  for i in range(N):
    rsum=rsum+r[i]
  rindex=int(rsum/x)
  lindex=N-int(rsum/x)
  for i in range(lindex):
    need+=r[i]
  if need<=K:
    ans=max(ans,x)
print(int(ans))
