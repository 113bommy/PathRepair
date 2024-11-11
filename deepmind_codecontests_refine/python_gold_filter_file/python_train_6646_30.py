from collections import Counter

N,M=map(int,input().split())

L=[]
for i in range(N):
    A=list(map(int,input().split()))
    L.append(A)
    
OUTD=dict()
S=[0 for i in range(N)]

ANS=1000
for i in range(M):
    B=[0 for _ in range(N)]
    for j in range(N):
        for k in range(S[j],M):
            if L[j][k] in OUTD:
                S[j]+=1
            else:
                B[j]=L[j][k]
                break
    X=Counter(B).most_common()[0]
    if X[1]<ANS:
        ANS=X[1]
    OUTD[X[0]]=1
    #print(ANS,B,OUTD)
print(ANS)