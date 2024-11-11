n,a,b = map(int, input().split())
mod = 10**9+7
 
def minus(n,k):
    x,y =1,1
    for i in range(k):
        x*=(n-i)%mod
        y*=(k-i)%mod
    return x*pow(y, mod-2, mod)%mod
 
ans = pow(2,n,mod)-1-minus(n,a)-minus(n,b)
while ans<0:
    ans+=mod
print(ans)