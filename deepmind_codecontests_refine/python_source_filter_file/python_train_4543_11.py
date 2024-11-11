mod=1e9+7
def power(n,k):
    r=1
    while(k!=0):
        if(k%2!=0):
            r=(r*n)%mod
            k-=1
        else:
            n=(n*n)%mod
            k=k//2
    return r
n,m,k=map(int,input().split())
if(k==-1 and (m+n)%2!=0):
    print(0)
else:
    print(power(power(2,m-1),n-1))
    