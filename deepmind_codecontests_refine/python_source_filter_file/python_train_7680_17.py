m=10**9+7;f=[1];n,k=map(int,input().split())
for i in range(10**6):f+=[f[i]*(i+1)%m]
def c(a,b):return f[a]*pow(f[b],m-2,m)*pow(f[a-b],m-2,m)%m
s=c(n*2-1,n-1)
if k>n-2:print(s)
else:print(s+(m-sum(c(n-1,i)*c(n,n-i)for i in range(n-1,k,-1))%m)%m)