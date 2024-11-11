n,k=map(int,input().split())
ans=0
for i in range(1,2):
  i*=k
  if i%2==0:
    ans+=(n//(i//2)-n//i)**3
  ans+=(n//i)**3
print(ans)