N = int(input())
_L = list(map(int,input().split()))

L =[(v,i) for i,v in enumerate(_L)]
L = sorted(L,key = lambda x:(-x[0],-x[1]))

dp = [[0]*(N+1) for _ in range(N+1)]

for i in range(N):#i番目の数字まで見た
    for k in range(N):#k回(i-pi)のパターン
        if k>i:
            continue
        val,ind = L[i]
        dp[i+1][k+1] = max(dp[i+1][k+1],dp[i][k] + val * abs(ind-k))#先頭からk番目に動かす
        dp[i+1][k] = max(dp[i+1][k],dp[i][k]+val * abs(N-1-(i-k)-ind))#すでに後ろからi-k個は使ってる=>後ろからN- (i-k)+1番目に動かす
print(max(dp[-1]))


