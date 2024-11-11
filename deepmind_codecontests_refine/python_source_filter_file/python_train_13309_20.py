N=int(input())
A=list(map(int,input().split()))
ind=1
res=10**10+1
for isplus in (True,False):
  cur=0
  ans=0
  for i in range(N):
    cur+=A[i]
    if isplus:
      if cur<=0:
        ans+=abs(cur-1)
        cur=1
      isplus=False
    else:
      if cur>=0:
        ans+=abs(cur-(-1))
        cur=-1
      isplus=True
  if res>ans:
    res=ans

print(res)