S = input()
n = len(S)
p = 10**9+7
DP = [[0]*13 for i in range(n+1)]
DP[0][0] = 1
for i in range(1, n+1):
    for j in range(13):
        if S[i-1] == '?':
            DP[i][j] = sum([DP[i-1][(4*(j-k)) % 13] for k in range(10)]) % p
        else:
            k = int(S[i-1])
            DP[i][j] = DP[i-1][(4*(j-k)) % 13]
print(DP[n][5])
