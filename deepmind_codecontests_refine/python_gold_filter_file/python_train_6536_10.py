r1,c1,r2,c2=map(int,input().split())
a=r2-r1+1
b=c2-c1+1
m=max(a,b)
n=min(a,b)
mod=10**9+7
def framod(n, mod, a=1):
    for i in range(1,n+1):
        a=a * i % mod
    return a
def comb(n, k, mod):
    a=framod(n, mod)
    b=framod(k, mod)
    c=framod(n-k, mod)
    return (a * pow(b, mod-2, mod) * pow(c, mod-2, mod)) % mod
def f(x,y):
  return comb(x+y+2,y+1,mod)-1
 
print((f(r2,c2)-f(r2,c1-1)-f(r1-1,c2)+f(r1-1,c1-1))%mod)