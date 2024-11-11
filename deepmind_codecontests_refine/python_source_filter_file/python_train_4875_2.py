N,M=map(int,input().split())
ab=[tuple(map(int,input().split())) for i in range(M)]

ab.sort()
l=1,r=N
ans=1
for a,b in ab:
  l=max(a,l)
  r=min(b,r)
  if l>=r:
    ans+=1
    l=a
    r=b
print(ans)
  