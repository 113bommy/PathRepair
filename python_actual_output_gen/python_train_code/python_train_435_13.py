N,K = map(int,input().split())
A = list(map(int,input().split()))

dp = [0] * (K+1)

for i in range(0,K+1):
    if dp[i] == 0:
        for j in A:
            if i + j > K:
                break
            dp[i + j] = 1

print('first' if dp[K] else 'second')