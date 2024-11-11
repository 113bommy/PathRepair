n,k=map(int,input().split())
l=list(map(int,input().split()))
ans=1e20
for i in range(n-k):
  r=i+k-1
  p1=abs(l[i])+abs(l[r]-l[i]);p2=abs(l[r])+abs(l[i]-l[r])
  ans=min(ans,p1,p2)
print(ans)