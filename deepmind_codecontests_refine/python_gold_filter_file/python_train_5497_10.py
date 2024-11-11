N, K = map(int,input().split())
MOD = 10**9 + 7

state= [] # 同じ状態とみなしてよいものの個数の配列
i = 1
while i <= N:
    if i*i <= N:
        state.append(1)
        i += 1
    else:
        j = N // i # iの後における最大の数
        state.append(N//j-i+1) 
        i = N//j + 1

L = len(state)
#print(state)

# dp[k][x] : 最後が状態xであるようなk個の整数を並べる場合の数
dp = [[0]*L for _ in range(K+1)]
dp[0][0] = 1

#dp[k+1][x] = sum_{y: xを後ろにおける状態} dp[k][y]
for k in range(K):
    cum_sum = [0] * (L+1)
    for y in range(L): 
        cum_sum[y+1] = (cum_sum[y] + dp[k][y]) % MOD

    for x in range(L):
        # xを後ろにおけるような最大の状態はL-x-1
        dp[k+1][x] += cum_sum[L-x]
        dp[k+1][x] *= state[x]
        dp[k+1][x] %= MOD

#print(dp)
print(sum(dp[K]) % MOD)