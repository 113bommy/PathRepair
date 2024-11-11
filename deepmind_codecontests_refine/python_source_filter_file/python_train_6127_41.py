n,m=map(int,input().split())
if n<=2*m:
  res=m-2*n
  ans=n+res//4
else:
  ans=m//2
print(ans)