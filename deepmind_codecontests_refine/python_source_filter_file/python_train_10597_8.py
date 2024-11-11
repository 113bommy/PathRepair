#dpがやや特殊なので、1次元的に走査したほうがよさそう。initializeもいらないし。
n,m = map(int, input().split())

inf = 10**9

dp =[inf for _ in range(2**n)]
dp[0] = 0

for i in range(m):
    a,b = map(int, input().split())
    d = sum((1<<(i-1)) for i in map(int, input().split()))
  
    for j in range(2**n):
        jord = j | d
        dp[i][jord] = min(dp[i][jord], dp[i][j] + a)
            
if dp[-1] == inf:
    print(-1)
else:
    print(dp[-1])