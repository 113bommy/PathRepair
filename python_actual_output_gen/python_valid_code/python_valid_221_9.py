n,x=map(int,input().split())
l=list(map(int,input().split()))
ans,d=0,0

for i in l:
  d+=i
  if d<=x:
    ans+=1
  else:
    break
print(ans)
