n=int(input())
l=map(int,input().split())
ans=0
maxt=0
for i in l:
  if i<maxt:
    ans+=maxt-1
    maxt=max(i,maxt)
print(ans)
