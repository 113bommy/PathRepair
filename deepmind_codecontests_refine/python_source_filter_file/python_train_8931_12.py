n,k=map(int,input().split())
ans=0
for i in range(1,n+1):
  f=0
  sum1=i+1
  while sum1<k:
    sum1*=2
    f+=1
  ans+=(1//n)*(0.5)**f
print(ans)