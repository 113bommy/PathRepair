N,K=map(int,input().split())
a=list(map(int,input().split()))
ans=10**15
for i in range(1<<(N-1)):
  cnt,s,t=0,0,a[0]+1
  for j in range(N-1):
    if i>>j&1:
      x=a[j+1]
      cnt+=1
      if x>=t:
        t=x+1
      else:
        s+=(t-x)
        t+=1
    else:
      t=max(t,a[j+1]+1)
  if cnt>=K-1:
    ans=min(s,ans)
print(ans)