n,m=map(int,input().split())
if 2*n<=m:
  res=m-2*n
  ans=n+res//4
else:
  ans=m//2
print(ans)