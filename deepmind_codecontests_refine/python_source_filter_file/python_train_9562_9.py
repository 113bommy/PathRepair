n,t=map(int,input().split())
a=list(map(int,input().split()))
ans=0
for i in range(n-1):
  if a[i+1]-a[i]>=t:
    ans+=4
  else:
    ans+=(a[i+1]-a[i])
print(ans+t)