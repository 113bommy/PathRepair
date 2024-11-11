n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
c=[0]*60
for aa in a:
  for i in range(60):
    if aa&(1<<i):c[i]+=1
ans=0
for i,cc in enumerate(c):
  ans+=cc*(n-cc)*2**i
  ans%=mod
print(ans)


