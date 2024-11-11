import sys
sys.setrecursionlimit(500*500)
def modpow(a,n,p):
    if n==0:
        return 1
    x=modpow(a,n//2,p)
    x=(x*x)%p
    if (n%2)==1:
        x=(x*a)%p
    return x%p
def modinv(a,p):
    return modpow(a,p-2,p)

r1,c1,r2,c2=map(int,input().split())
n1=r2+c2+2
n2=r2+c1+1
n3=r1+c2+1
n4=r1+c1
l=[r2+1,r2+1,r1,r1]
p=10**9+7
buf=1
cnt=0
l=[0]*(10**6+10)
inv=[0]*(10**6+10)
l[1]=1
for i in range(2,n1+3,1):#n1+1
    l[i]=(l[i-1]*i)%p
print((((l[n1]*modinv(l[r2+1],p)*modinv(l[n1-r2-1],p))%p)-(l[n2]*modinv(l[r2+1],p)*modinv(l[n2-r2-1],p))-(l[n3]*modinv(l[r1],p)*modinv(l[n3-r1],p))+(l[n4]*modinv(l[r1],p)*modinv(l[n4-r1],p)))%p)