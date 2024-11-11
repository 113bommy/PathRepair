n,t=map(int,input().split())
arr=map(int,input().split())

ans=0
for i in arr:
  t-=i
  ans+=1
  if t<=0:
    break
print(ans)