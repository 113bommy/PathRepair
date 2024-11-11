n=int(input())
a=list(map(int,input().split()))

mod=10**9+7

ans=0
for i in range(60):
  on=0
  off=0
  for j in a:
    if (j>>i)&1:
      on+=1
    else:
      off+=1
  ans+=(on*off)*(2**i)
  ans%=mod

print(ans)