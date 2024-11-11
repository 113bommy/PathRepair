n=int(input())
ans=10**18
for i in range(10**6+1):
  if n%i==0:
    j=n//i
  ans=min(ans,i+j-2)
print(ans)