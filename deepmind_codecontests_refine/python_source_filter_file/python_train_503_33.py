n,a = map(int,input().split())
xl = list(map(int,input().split()))

# i個のカードまで使って和がjの組み合わせ
dp = [[0 for i in range(50*50+1)] for j in range(51)]
dp[0][0] = 1

for i in range(n):
    for j in range(n, -1, -1):
        for k in range(50*50+1):
            if k+xl[i] < 50*50+1:
                dp[j+1][k+xl[i]] += dp[j][k]
ans = 0
for i in range(1,n+1):
    ans += dp[i][i*a]

print(ans)
