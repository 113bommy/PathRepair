n,k=map(int,input().split())
ans=0
while n>k:
  n/=k
  ans+=1

print(ans+1)