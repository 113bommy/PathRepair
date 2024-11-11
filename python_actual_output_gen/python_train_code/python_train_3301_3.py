n,t=map(int,input().split())
k=1000000000
for i in map(int,input().split()):
  ans+=min(t,max(i-k,0))
  k=i
ans+=t
print(ans)