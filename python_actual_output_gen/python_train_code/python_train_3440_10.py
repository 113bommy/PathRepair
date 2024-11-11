n=int(input())
ans=1
mod=10**7+1
m=1
for i in range(n):
    m*=(i+1)
for j in range(2,n+1):
    b=1
    while m%j==0:
        m=m//j
        b+=1
    ans*=b
ans=ans%mod
print(ans)