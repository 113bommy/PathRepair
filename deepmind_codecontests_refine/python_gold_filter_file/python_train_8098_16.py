N=int(input())
ans=0
for x in range(1,N+1):
  if len(str(x))%2==1:
    ans+=1
print(ans)