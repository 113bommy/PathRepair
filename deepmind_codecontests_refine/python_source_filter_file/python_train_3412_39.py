K=int(input())
ans=1
x=7
for i in range(K):
  if x!=0:
    ans+=1
    x=(x*10+7)%K
if x==0:
  print(ans)
else:
  print(-1)