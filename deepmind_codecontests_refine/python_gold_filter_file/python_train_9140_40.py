n = int(input())
P = [float(i) for i in input().split()]

DP = [[0] * (n+1) for j in range(n+1)]
DP[0][0] = 1

for i in range(n):
    for j in range(n):
        DP[i+1][j+1] += DP[i][j] * P[i]
        DP[i+1][j] += DP[i][j] * (1 - P[i])

print(sum(DP[n][(n+1)//2:]))