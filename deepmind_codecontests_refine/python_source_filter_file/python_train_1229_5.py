N,K = map(int,input().split())
A = list(map(int,input().split()))

dp = [0 for _ in range(K+1)]

for i in range(K):
    for j in range(N):
        if i-A[j] >= 0:
            dp[i] |= not dp[i-A[j]]
            
if dp[K]:
    print('First')
else:
    print('Second')