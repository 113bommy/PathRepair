N = [int(n) for n in list(input())]
d = int(input())
p = 10**9+7
DP = [[0]*d, [0]*d]
DP[1][0] = 1
for n in N:
    DP_ = [[0]*d, [0]*d]
    for i in range(2):
        for j in range(d):
            for k in range(n+i):
                DP_[i][j] += DP[1][(j-k) % d] % p
            for k in range(n+i, 10):
                DP_[i][j] += DP[0][(j-k) % d] % p
            DP_[i][j] %= p
    DP = DP_
print((DP[1][0] + p - 1) % p)
