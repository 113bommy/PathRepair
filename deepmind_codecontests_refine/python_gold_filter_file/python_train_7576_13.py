from fractions import gcd

N=int(input())
A=list(map(int,input().split()))

g=A[0]
l=A[0]
for i in range(N):
    g=gcd(l,A[i])
    l=l*A[i]//g
    
ans=0
mod=10**9+7

for i in range(N):
    ans+=l//A[i]
    
print(ans%mod)
    
