import io, os
import sys
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

D=int(input())
q=int(input())
mod=998244353
Q=[tuple(map(int,input().split())) for i in range(q)]

from math import gcd
from math import sqrt

L=[]
Q2=[]
for x,y in Q:
    GCD=gcd(x,y)
    x//=GCD
    y//=GCD
    Q2.append((x,y))
    L.append(x)
    L.append(y)

FACTOR=set()

for l in L:
    for f in FACTOR:
        while l%f==0:
            l//=f
    if l==1:
        continue
    else:
        L=int(sqrt(l))
        for i in range(2,L+2):
            while l%i==0:
                FACTOR.add(i)
                l//=i
        if l!=1:
            FACTOR.add(l)


FACT=[1]
for i in range(1,2*10**2+1):
    FACT.append(FACT[-1]*i%mod)

FACT_INV=[pow(FACT[-1],mod-2,mod)]
for i in range(2*10**5,0,-1):
    FACT_INV.append(FACT_INV[-1]*i%mod)

FACT_INV.reverse()

def Combi(a,b):
    if 0<=b<=a:
        return FACT[a]*FACT_INV[b]*FACT_INV[a-b]%mod
    else:
        return 0


def FACTORIZE(x):

    F=[]

    for f in FACTOR:
        #print(f,x)
        a=0
        while x%f==0:
            a+=1
            x//=f
        if a!=0:
            F.append(a)
    return F

for x,y in Q2:
    ANS=1
    
    F=FACTORIZE(x)
    S=sum(F)
    for f in F:
        ANS=ANS*Combi(S,f)%mod
        S-=f

    F=FACTORIZE(y)
    S=sum(F)
    for f in F:
        ANS=ANS*Combi(S,f)%mod
        S-=f

    sys.stdout.write(str(ANS%mod)+"\n")

