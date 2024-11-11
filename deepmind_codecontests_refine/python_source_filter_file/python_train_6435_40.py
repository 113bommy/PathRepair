K=input()
D=int(input())
mod=10**9+7

L=len(K)

DP=[0]*D#DP[num][limit]で,一つ前の桁について,「桁和,そこまでKと一致していれば1」の場合の数
LIMIT=[]

for j in range(10):
    if j>int(K[0]):
        continue
    if j==int(K[0]):
        LIMIT=j%D
    else:
        DP[j%D]+=1

for ketanum in K[1:]:
    NDP=[0]*D

    for i in range(D):
        for j in range(10):
            NDP[(i+j)%D]=(NDP[(i+j)%D]+DP[i])%mod

    for j in range(int(ketanum)):
        NDP[(LIMIT+j)%D]+=1

    LIMIT=(LIMIT+int(ketanum))%D

    DP=NDP

print((DP[0]-1+ (LIMIT==0) )%mod)
