n,k=map(int,input().split())
ans=0
while(n>1):
  n/=k; ans+=1
print(ans)