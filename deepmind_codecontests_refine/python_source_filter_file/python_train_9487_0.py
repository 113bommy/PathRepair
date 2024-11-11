x,k=map(int,input().split())
#x=60
#k=5
if x==1:
    print(1)
    import sys
    sys.exit()

import math 
L=int(math.sqrt(x))
mod=10**9+7
FACT=dict()

for i in range(2,L+2):
    while x%i==0:
        FACT[i]=FACT.get(i,0)+1
        x=x//i

if x!=1:
    FACT[x]=FACT.get(x,0)+1


def prod(A,B,k,l,m):#A:k*l,B:l*m
    C=[[None for i in range(m)] for j in range(k)]

    for i in range(k):
        for j in range(m):
            ANS=0
            for pl in range(l):
                ANS=(ANS+A[i][pl]*B[pl][j])%mod

            C[i][j]=ANS

    return C

def plus(A,B,k,l):#a,B:k*l
    C=[[None for i in range(l)] for j in range(k)]

    for i in range(k):
        for j in range(l):
            C[i][j]=(A[i][j]+B[i][j])%mod

    return C
    

#XX=[[1,1],[1,1],[1,1]]
#YY=[[2,2,2],[2,3,4]]
#print(prod(XX,YY,3,2,3))

MAT_index=max(FACT.values())+1
MAT=[[0 for i in range(MAT_index)] for j in range(MAT_index)]

for m in range(MAT_index):
    for l in range(m+1):
        x=pow(m+1,mod-2,mod)
        MAT[m][l]=x

#print(MAT)

       
#MAT_ini=MAT
#for i in range(k-1):
#    MAT=prod(MAT,MAT_ini,MAT_index,MAT_index,MAT_index)

#ここをダブリング

MAT_dob=[None]*13
MAT_dob[0]=MAT
for i in range(1,13):
    MAT_dob[i]=prod(MAT_dob[i-1],MAT_dob[i-1],MAT_index,MAT_index,MAT_index)

MAT=[[0 for i in range(MAT_index)] for j in range(MAT_index)]
for i in range(MAT_index):
    MAT[i][i]=1

for i in range(13):
    if k & 1<<i !=0:
        #print(i,MAT,MAT_dob[i])
        MAT=prod(MAT,MAT_dob[i],MAT_index,MAT_index,MAT_index)
        #print(MAT)


#print(MAT)

ANS=1
for fa in FACT:
    x=FACT[fa]
    ANS_fa=0

    for i in range(x+1):
        ANS_fa=(ANS_fa+pow(fa,i,mod)*MAT[x][i])%mod

    ANS=ANS*ANS_fa%mod

print(ANS)
