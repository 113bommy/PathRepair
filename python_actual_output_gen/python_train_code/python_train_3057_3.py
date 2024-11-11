MOD=1000000009;
def solve(a,n):
    ans=1;
    p=a;
    while(n>0):
        if(n%2==1): ans*=p;
        n/=2;
        ans%=MOD;
        p=(p*p)%MOD;
    return ans;
n,m,k=map(int,input().split());
p=n-m+1;
if((k-1)*p>=m):
    print(m);
else:
    v=m-(p-1)*(k-1);
    ans=(p-1)*(k-1);
    t=v//k;
    ans=(ans+k*(solve(2,t)-1)*2%MOD+MOD+v%k)%MOD;
    print(ans);