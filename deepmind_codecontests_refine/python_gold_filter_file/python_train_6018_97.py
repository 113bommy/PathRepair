S = input()
g = 10 ** 9 + 7
x = 1
DP = [[0] * 13 for _ in range(2)]
DP[0][0] = 1
for i in range(len(S)):
    for j in range(13):
        DP[1][j] = DP[0][j] % g
        DP[0][j] = 0
    for j in range(13):
        if S[i] == "?":
            for k in range(10):
               DP[0][(j*10+k)%13] += DP[1][j]
        else:
            DP[0][(j*10+int(S[i]))%13] += DP[1][j]

print(DP[0][5] % g)
