n,k=map(int,input().split())
a=[0]+list(map(int,input().split()))
for i in range(n):
  a[i+1]+=a[i]
d=[]
for i,x in enumerate(a):
  for y in a[:i]:
    d+=[x-y]
ans=0
t=2**41
for _ in range(41):
  cnt=0
  for j in d:
    cnt+=(ans+t)&j==(ans+t)
  if cnt>=k:ans+=t
  t//=2
print(ans)