def solve(n,x,k):
  ans=-10**20
  s=0
  sx=sum(x)
  for i in range(n):
    if (i+1)>k:break
    s+=x[i]
    d=((k-i-1)//n)*sx
    ans=max(ans,s+d,s)
  return ans

n,k=map(int,input().split())
p=list(map(lambda x:int(x)-1,input().split()))
c=list(map(int,input().split()))
ans=-10**20
for i in range(n):
  x=[c[i]]
  j=p[i]
  while i!=j:
    x.append(c[j])
    j=p[j]
  x=x[1:]+[x[0]]
  ans=max(ans,solve(len(x),x,k))
print(ans)
