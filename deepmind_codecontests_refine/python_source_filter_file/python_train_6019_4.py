n = int(input())
C = [0] + [int(input()) for i in range(n)]
p = 10 ** 9 + 7

DP = [0] * (n + 1)
last = [0] * (n + 1)
DP[0] = 1

for i in range(n):
    if C[i + 1] == C[i]:
        DP[i + 1] = DP[i] % p
    else:
        DP[i + 1] = (DP[i] + last[C[i + 1]]) % p
    last[C[i + 1]] = DP[i + 1]

print(DP[n])