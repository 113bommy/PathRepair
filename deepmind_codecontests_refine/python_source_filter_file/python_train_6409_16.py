import bisect
n,m,k=map(int,input().split())
x,s=map(int,input().split())
a=list(map(int,input().split()))+[x]
b=list(map(int,input().split()))+[0]
c=[0]+list(map(int,input().split()))
d=[0]+list(map(int,input().split()))
l=sorted(list(zip(a,b)),key=lambda x:-x[1])
ans,j=n*x,0
for ai,bi in l:
  while j<=k and d[j]+bi<=j:
    j+=1
  if j==0:
    continue
  ans=min(ans,ai*(n-c[j-1]))
print(ans)