a,b,c,d=map(int,input().split())
ans=min(c,d)-max(a,b)
if ans<=0:
  print(0)
else:
  print(ans)