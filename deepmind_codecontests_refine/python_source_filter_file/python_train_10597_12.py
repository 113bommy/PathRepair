n, m = map(int, input().split())
ac = []
for _ in range(m):
    a,_ = map(int, input().split())
    c = sum([2**(int(i)-1) for i in input().split()])
    ac.append([a, c])
dp = [float('inf')] * 2**n
dp[0] = 0
for s in range(2**n):
    for a, c in ac:
        t = s|c
        cost = dp[s] + a
        dp[t] = min(dp[t], cost)
ans = dp[-1]
if ans == float('inf'):
    ans = -1
print(ans)