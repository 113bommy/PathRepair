n = int(input())
*P, = map(float, input().split())
DP = [0 for j in range(n+1)]
DP[0] = 1
for i in range(n):
    DP_ = []
    DP_.append(DP[0]*(1-P[i]))
    for j in range(1, n+1):
        DP_.append(DP[j]*(1-P[i])+DP[j-1]*P[i])
    DP = DP_
print(sum(DP[(n+1)//2:]))
