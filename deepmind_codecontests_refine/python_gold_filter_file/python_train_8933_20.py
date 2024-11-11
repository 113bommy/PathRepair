n,a,b,k=map(int,input().split())
if k==0:
    print(1)
    quit()
mod=998244353
fra=[1]*(n+2)
inv=[1]*(n+2)
t1=1
t2=1
for i in range(1,n+2):
    t1*=i
    t1%=mod
    t2*=pow(i,mod-2,mod)
    t2%=mod
    fra[i]=t1
    inv[i]=t2
def comb(n,r):
    return fra[n]*inv[n-r]*inv[r]%mod
ans=0
for i in range(max(0,-(-(k-b*n)//a)),min(n+1,k//a+1)):
    t=k-i*a
    if t>b*n or t%b!=0:
        continue
    else:
        t//=b
        ans+=(comb(n,i)*comb(n,t))%mod
        ans%=mod
print(ans)