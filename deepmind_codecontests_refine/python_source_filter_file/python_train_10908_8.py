n,k=map(int,input().split())
l=[0]*(k+1)
a=0
mod=10**9+7
for i in range(1,k+1):
  l[i]=i
  for j in range(i*2,k+1,i):
    l[j]-=l[i]
  a+=l[i]*pow(k//i,n,mod)
print(a%mod)