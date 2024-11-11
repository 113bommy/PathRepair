import sys


# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

input = sys.stdin.readline
MOD = 10**9+7

t, k = list(map(int, input().split()))
a = []
max_ = 0

while t:
    t -= 1

    a.append(list(map(int, input().split())))
    max_ = max(max_, a[-1][1])

dp = [1]*(max_+1)
for i in range(k, max_+1):
    dp[i] = (dp[i-k] + dp[i-1])%MOD

for i in range(1, max_+1):
    dp[i] += dp[i-1]
    dp[i] %= MOD

for a_, b_ in a:
    print(dp[b_]-dp[a_-1])
    


    