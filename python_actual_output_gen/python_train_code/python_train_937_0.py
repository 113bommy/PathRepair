mod= 998244353

n,m,k=map(int,input().split())

ans=0
cmb=1
for i in range(k+1):
    ans+=cmb*m*pow(m-1,n-1-i,mod)
    ans%=mod
    X=(n-1-i)*pow(i+1,mod-2,mod)
    X%=mod
print(ans)