import sys
input = sys.stdin.readline

N=int(input())
POINT=[list(map(int,input().split())) for i in range(N)]
mod=998244353

PX=[p[0] for p in POINT]
PY=[p[1] for p in POINT]

compression_dict_x={a: ind for ind, a in enumerate(sorted(set(PX)))}
compression_dict_y={a: ind for ind, a in enumerate(sorted(set(PY)))}

for i in range(N):
    POINT[i]=[compression_dict_x[POINT[i][0]]+1,compression_dict_y[POINT[i][1]]+1]


P_Y=sorted(POINT,key=lambda x:x[1])

# BIT(BIT-indexed tree)

LEN=len(compression_dict_x)# 必要なら座標圧縮する

BIT=[0]*(LEN+1)# 1-indexedなtree

def update(v,w):# vにwを加える
    while v<=LEN:
        BIT[v]+=w
        v+=(v&(-v))# 自分を含む大きなノードへ. たとえばv=3→v=4

def getvalue(v):# [1,v]の区間の和を求める
    ANS=0
    while v!=0:
        ANS+=BIT[v]
        v-=(v&(-v))# 自分より小さい2ベキのノードへ. たとえばv=3→v=2へ
    return ANS


ALL = pow(2,N,mod)-1

ANS= ALL*N%mod

for i in range(N):
    ANS = (ANS - (pow(2,i,mod) -1)*4)%mod

for i in range(N):
    x,y=P_Y[i]
    up=getvalue(x)

    ANS=(ANS+pow(2,up,mod)+pow(2,i-up,mod)-2)%mod

    update(x,1)

P_Y2=P_Y[::-1]
BIT=[0]*(LEN+1)

for i in range(N):
    x,y=P_Y2[i]
    down=getvalue(x)

    ANS=(ANS+pow(2,down,mod)+pow(2,i-down,mod)-2)%mod

    update(x,1)


print(ANS)
