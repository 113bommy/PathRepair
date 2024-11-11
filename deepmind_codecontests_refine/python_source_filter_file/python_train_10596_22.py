x,k=map(int,input().split())
ans=0
while k**ans<x:
  ans+=1
print(ans)