n,a,b=map(int,input().split())
ans=b*(n-1)+a-a*(n-1)-b
if ans<=0:
  print(0)
else:
  print(ans)