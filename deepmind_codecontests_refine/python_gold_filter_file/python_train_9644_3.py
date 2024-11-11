N = 1030
MOD = int(1e9+7)
c = [[0] * N for i in range(N)]
for i in range(N):
    c[i][0] = 1
for i in range(1, N):
    for j in range(1, N):
        c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD

arr = list(map(int, list(input())))
cnt = int(input())
if cnt == 0:
    print(1)
    exit()

dp = [0] * N
for i in range(2, N):
    dp[i] = dp[bin(i).count('1')] + 1
res = 0
for i in range(1, N):
    if dp[i] != cnt - 1:
        continue
    n, k = len(arr)-1, i
    for pos in range(len(arr)):
        if arr[pos] == 1:
            res = (res + c[n][k]) % MOD
            k -= 1
        n -= 1
    if n == -1 and k == 0:
        res += 1
if cnt == 1: 
    res -= 1
print(res)