a,b=map(int,input().split())
ans=0
for i in range(a,b+1):
  s=str(i)
  if i[0]==i[4] and i[1]==i[3]:
    ans+=1
print(ans)