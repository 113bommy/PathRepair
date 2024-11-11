from bisect import bisect_left
n=int(input())
c=sorted(list(map(int,input().split())))
mod=10**9+7
#2のx乗を前計算(mod)(0~N-1)
p=[1]*(n+1)
for i in range(n):
    p[i+1]=p[i]*2
    p[i+1]%=mod
ans=0
#それ以上のもの
for i in range(n):
    b=bisect_left(c,c[i])
    x=n-i-1
    ans+=(p[x]+x*p[x-1])*c[i]*p[i]
    ans%=mod
print(ans*p[n]%mod)