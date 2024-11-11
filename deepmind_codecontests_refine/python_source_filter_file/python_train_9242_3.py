n,k=[int(i) for i in input().split()]
arr=[int(i) for i in input().split()]
ans=0
mod=10**9+7
arr.sort() 
c=[0 for i in range(n)]
r=k-1
c[r]=1
def modinv(x.mod):
    return pow(x,mod-2,mod)
for i in range(r+1,n):
    c[i]=((c[i-1]*(i))*modinv(i-r,mod))%mod
pos=0
neg=0
for i in range(n):
    pos+=(arr[-1-i]*c[-1-i])%mod
    neg+=(arr[i]*c[-1-i])%mod
    pos%=mod
    neg%=mod
print((pos-neg)%mod)
