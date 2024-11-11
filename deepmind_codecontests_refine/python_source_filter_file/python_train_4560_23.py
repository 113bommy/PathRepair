n,k=map(int,input().split())
a=list(map(int,input().split()))
f=list(map(int,input().split()))
a.sort()
f.sort(reverse=1)
su=ok=ng=0
for i in range(n):
  ok=max(ok,a[i]*f[i])
  su+=a[i]
if su<=k:print(0);exit()
while ng+1<ok:
  mid=(ok+ng)//2
  h=0
  for i in range(n):
    h+=a[i]-(mid//f[i])
  if h<=k:ok=mid
  else:ng=mid
print(ok)