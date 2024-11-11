n = int(input())
S = [int(x) for x in input().split(' ')]
C = [int(x) for x in input().split(' ')]
dp = [float('inf')] * n
ans = float('inf')
# for i in range(n):
#     for j in range(i + 1, n):
#         if S[j] > S[i] and C[j] < dp[i]:
#             dp[i] = C[j]

for i in range(n):
    for j in range(i + 1, n):
        if S[j] > S[i]:
            ans = min(ans, C[i] + C[j] + dp[j])
if ans == float('inf'):
    ans = -1
print(ans)
