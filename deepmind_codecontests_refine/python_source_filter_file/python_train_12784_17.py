n,x=map(int,input().split())
a=list(map(in,input().split()))

ans=1
d=0

for i in a:
  d+=i
  if d>x:
    break
  ans+=1
  
print(ans)