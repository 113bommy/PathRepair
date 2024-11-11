n,m = map(int,input().split())
dp = [float('inf')]*(1<<n)
dp[0] = 0
for _ in range(m):
    a,b = map(int,input().split())
    sc = 0
    for e in map(int,input().split()):
        bit += 1<<(e-1)
    for i in range(1<<n):
        dp[i|bit] = min(dp[i|bit], dp[i]+a)
if dp[-1] == float('inf'):
    print(-1)
else:
    print(dp[-1])