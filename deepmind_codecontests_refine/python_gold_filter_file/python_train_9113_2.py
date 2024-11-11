import math
n, k = [int(x) for x in input().split()]
if n<70 and k>2**n:
    print(1,1)
    exit(0)
mod = int(1e6)+3

def fastpow(a,b):
    t, ans = a, 1
    while b:
        if(b&1):
            ans = ans*t%mod
        t = t*t %mod
        b>>=1
    return ans

t=k-1
cnt=0
while t:
    cnt += t>>1
    t>>=1

x=0
t=fastpow(2,n)
if k<mod:
    x=1
    for i in range(1,k):
        x = x*(t-i)%mod
y=fastpow(2,n*(k-1))

inv = fastpow(2,mod-2)
inv = fastpow(inv,cnt)

x=(x*inv%mod+mod)%mod
y=(y*inv%mod+mod)%mod

x=(y-x+mod)%mod

print(x,y)