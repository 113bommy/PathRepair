import sys

input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int,input().split()))

dp = {a[i]:-1 for i in range(n)}
for i in range(30):
    next = {}
    for val in dp:
        if not val>>1 in next:
            next[val>>1] = - dp[val]
        else:
            if next[val>>1]<0:
                next[val>>1] = max(-next[val>>1],dp[val])
            else:
                next[val>>1] = max(next[val>>1],abs(dp[val]))
    dp = next
    for d in dp:
        if dp[d]>0:
            dp[d] = dp[d] + 1
        else:
            dp[d] = -dp[d]


print(n-dp[0])
