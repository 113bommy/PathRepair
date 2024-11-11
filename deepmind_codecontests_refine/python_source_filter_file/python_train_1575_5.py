s=input().split()
n,m,k=list(map(int,s))
MOD=998244353
ans=m
for i in range(k-1):
    ans=(ans*(m-1))%MOD
if k>n//2:
    k=n-k
for i in range(1,k+1):
    ans=ans*(n-1-k+i)//i
print(ans%MOD)