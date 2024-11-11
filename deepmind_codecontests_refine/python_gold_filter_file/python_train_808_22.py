n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
ans=0
for k in range(60):
  t=1<<k
  z=o=0
  for i in a:
    if i&t:o+=1
    else:z+=1
  ans=(ans+(z*o*t))%mod
print(ans)
