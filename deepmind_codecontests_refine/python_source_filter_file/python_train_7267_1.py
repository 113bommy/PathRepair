n = int(input())
a = list(map(int, input().split()))

dp = [[[0]*(n+1) for _ in range(n+1)] for _ in range(n+1)]
dp[0][0][0] = 0

cnt1 = a.count(1)
cnt2 = a.count(2)
cnt3 = a.count(3)

for i in range(cnt3 + 1):
    for j in range(cnt3 + cnt2 + 1 - i):
        for k in range(cnt3 + cnt2 + cnt1 + 1 - i - j):
            if i + j + k == 0:
                continue
            res = 1
            if k > 0:
                res += (k/n) * dp[i][j][k-1]
            if j > 0:
                res += (j/n) * dp[i][j-1][k+1]
            if i > 0:
                res += (i/n) * dp[i-1][j+1][k+1]
            dp[i][j][k] = (n/(i+k+j)) * res

print(dp[cnt3][cnt2][cnt1])
