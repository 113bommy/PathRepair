import sys
input = sys.stdin.readline

N=int(input())
A=[list(map(int,input().split())) for i in range(N)]
mod=10**9+7

#bitDP
DPLIST=[-1]*(2**N)
DPLIST[2**N-1]=1

def dp(NOW,x):

    if DPLIST[NOW]!=-1:
        return DPLIST[NOW]

    ANS=0

    for i in range(N):
        if A[x][i]==1 and NOW & (1<<i) ==0:
            ANS+=dp(NOW+2**i,x+1)

    ANS%=mod
    DPLIST[NOW]=ANS
    return ANS

print(dp(0,0)%mod)