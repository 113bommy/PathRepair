N,K = map(int, input().split())
L = [0]*N
R = [0]*N
DP = [0]*(N+10)
DP[0] = 1
SDP = [0]*(N+10)
SDP[1] = 1
MOD=998244353
for i in range(K):
    L[i],R[i] = map(int, input().split())

for i in range(1,N):
    for j in range(K):
        l = max(0,i-R[j])
        r = max(0,i-L[j]+1)
        DP[i] += SDP[r] - SDP[l]
    SDP[i+1] = SDP[i] + DP[i]
print(DP[N-1]%MOD)
