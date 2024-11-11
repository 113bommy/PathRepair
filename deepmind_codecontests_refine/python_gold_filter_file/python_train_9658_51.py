n=int(input())
li=list(map(int,input().split()))
ans=0
for i in range(0,n,2):
  if li[i]%2==1:
    ans+=1
print(ans)