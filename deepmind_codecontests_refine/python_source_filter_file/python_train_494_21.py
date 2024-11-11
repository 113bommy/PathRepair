import math

n=int(input())
D={}
for _ in range(n):
    a,b=map(int, input().split())
    if a==0 and b==0:
        key=(0,0)
    elif a==0:
        key=(0,1)
    elif b==0:
        key=(1,0)
    else:
        if a<0:
            a=-a
            b=-b
        g=math.gcd(a, abs(b))
        key=(a/g, b/g)
    if key not in D:
        D[key]=0
    D[key]+=1

mod=10**9+7
ans=1
zz=0

for k1, v1 in D.items():
    if k1==(0,0):
        zz+=v1
        continue
    if v1==0:
        continue

    if k1[1]>0:
        k2=(k1[1], -k1[0])
    else:
        k2=(-k1[1], k1[0])

    if k2 not in D:
        ans=ans*pow(2, v1, mod)%mod
    else:
        v2=D[k2]
        m=(pow(2, v1, mod)+pow(2, v2, mod)-1)%mod
        ans=ans*m%mod
        D[k2]=0

print((ans+zz-1)%mod)
