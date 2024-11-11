s = list(input())
n = len(s)
dp = [[0]*13 for i in range(n+1)]
dp[0][0] = 1
for i in range(n):
    flag = 1 if s[i]=='?' else 0
    for a in range(10):#i+1桁目の数字(0-9)
        if flag==1 or s[i]==str(a):
            for j in range(13): #あまり(0-12)
                dp[i+1][(j*10+a)%13] += dp[i][j] #i桁目の余りの10倍とi桁目を足して余りをだす
    for j in range(13):
        dp[i+1][j]%=10**9+7
print(dp[n][5])
