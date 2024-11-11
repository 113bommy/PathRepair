import sys
input = sys.stdin.readline

N = int(input())
A = [int(input()) for _ in range(N)]

p1 = 0
p2 = 0
P1 = [0]
P2 = [0]
for a in A:
    if a == 0:
        p1 -= 2
        p2 += 1
    elif a % 2 == 0:
        p2 -= 1
    elif a % 2 == 1:
        p1 -= 1
        p2 += 1
    p1 += a
    P1.append(p1)
    P2.append(p2)

S = sum(A)
dp = [[0, 0, 0, 0] for _ in range(N+1)]

dp[N] = [P1[N], P1[N]+P2[N], -P1[N], 0]

for i in reversed(range(N)):
    dp[i][0] = max(dp[i+1][0], P1[i])
    dp[i][1] = max(dp[i+1][1], P2[i]+dp[i][0])
    dp[i][2] = min(dp[i+1][2], P2[i]-dp[i][1])
    dp[i][3] = min(dp[i+1][3], P1[i]+dp[i][2])

print(dp[0][3]+S)   
