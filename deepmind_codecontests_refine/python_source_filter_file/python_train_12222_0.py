def invmod( x , y , MOD ):
    return (x*pow(y,MOD-2,MOD))%MOD

s=input()
k=int(input())
n=len(s)
MOD=10**9+7
sumG = invmod( pow(2,k*n,MOD)-1 , pow(2,n,MOD)-1 , MOD)
ans=0
for i in range(len(s)):
    if(s[i]=='5' or s[i]=='0'):
        ans+=pow(2,i,MOD)
ans*=sumG
print(ans)
