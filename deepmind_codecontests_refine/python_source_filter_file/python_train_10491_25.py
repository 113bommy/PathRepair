n,k=map(int,input().split())
a=[0]*n
a=list(map(int,input().split()))
a=sorted(a)
mod=10**9+7
ans=1

if (k%2==0 or a[-1]>=0):
    mlt1=a[0]*a[1]
    mlt2=a[-2]*a[-1]
    l=0
    r=-1
    for i in range(k//2):
        if (mlt1>=mlt2):
            ans*=mlt1%mod
            l+=2
            if (l<=n-2):
                mlt1=a[l+1]*a[l]
        else:
            ans*=mlt2%mod
            r-=2
            if (r>=-n+1):
                mlt2=a[r-1]*a[r]
            ans%=mod
    if (k%2==1):
        ans*=a[r]
        ans%=mod
    
else:
    for i in range(k):
        ans*=a[n-1-i]
        ans%=mod
        
print(ans)