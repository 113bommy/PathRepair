N,K=map(int,input().split())
mod=10**9+7

import math
SQ=int(math.sqrt(N))

DP1=[1]*(SQ+1)
DP1[0]=0


DP2=[]

k=SQ

for i in range(SQ,0,-1):
    DP2.append(N//i-k)
    k=N//i


KOSUU2=[v for v in DP2]

#print(DP1)
#print(DP2)
#print()

for j in range(K-1):
    NDP1=[0]*(SQ+2)
    NDP2=[0]*(SQ+1)

    for j in range(1,SQ+1):
        NDP2[-j]-=DP1[j]
        NDP1[1]+=DP1[j]

    #print(NDP1)
    #print(NDP2)
    #print()

    for j in range(-1,-SQ-1,-1):
        NDP1[-j+1]-=DP2[j]
        NDP1[1]+=DP2[j]

    #print(NDP1)
    #print(NDP2)
    #print()

    for j in range(1,SQ+2):
        NDP1[j]+=NDP1[j-1]

    NDP2[0]+=NDP1[-1]

    for j in range(1,SQ+1):
        NDP2[j]+=NDP2[j-1]

    #print(NDP1)
    #print(NDP2)
    #print()

    for j in range(SQ):
        NDP2[j]=NDP2[j]*KOSUU2[j]

    #print(NDP1)
    #print(NDP2)
    #print()

    DP1=[n%mod for n in NDP1[:SQ+1]]
    DP2=[n%mod for n in NDP2[:SQ]]

    
print((sum(DP1)+sum(DP2))%mod)
