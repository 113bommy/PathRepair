N=int(input())
p=list(map(float,input().split()))

DP=[0 for i in range(N+1)]
DP[0]=10**12
for i in range(N):
    #DP[0]=1
    for j in range(N+1):
        if DP[N-j]>0:
            DP[N-j+1]+=DP[N-j]*p[i]
            DP[N-j]*=(1-p[i])
    #print(DP)
print(sum(DP[N//2+1:])/(10**12))