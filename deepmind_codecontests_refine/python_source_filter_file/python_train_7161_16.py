import sys
input = sys.stdin.readline

N,T=map(int,input().split())
D=[tuple(map(int,input().split())) for i in range(N)]
D.sort()

DP=[0]*(T+1)
ANS=0

for i in range(N):
    a,b=D[i]

    for j in range(T,a-1,-1):
        DP[j]=max(DP[j-a]+b,DP[j])

    for j in range(i+1,N):
        ANS=max(ANS,DP[T-1]+D[j][1])

print(ANS)
