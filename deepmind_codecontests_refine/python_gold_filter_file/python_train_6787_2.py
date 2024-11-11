n,m=map(int,input().split())
a=[0]*10**6
Mod=10**9+7
a[1],a[2]=2,4
for i in range(3,max(n,m)+1):
    a[i]=(a[i-1]+a[i-2])%Mod
print((a[n]+a[m]-2)%Mod,flush=False)