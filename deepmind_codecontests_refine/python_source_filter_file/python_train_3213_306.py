x,y,d=map(int,input().split())
ans=y//d-x//d
if x==0:
  ans+=1
print(ans)