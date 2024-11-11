n,m,k=map(int, input().split( ))
mod = 998244353

ans=0
if m==1:##コーナー
  	print(1 if k==n-1 else 0)
    exit()
tmp=m*pow(m-1,n-1,mod)
m_inv=pow(m-1,mod-2,mod)
invs=[0]+[pow(i+1,mod-2,mod) for i in range(n)]
for i in range(1,k+2):
    ans+=tmp
    #print(ans)
    tmp*=m_inv
    if i<n:##?
        tmp*=n-i
        tmp*=invs[i]
    tmp%=mod
print(ans%mod)

