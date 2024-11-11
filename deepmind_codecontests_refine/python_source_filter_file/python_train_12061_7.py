N,W = map(int, input().split())
ws = []
vs = []
for i in range(N):
    w,v = map(int, input().split())
    ws.append(w)
    vs.append(v)
ws_m = [w-ws[0] for w in ws]

sum_ws_m = sum(ws_m)

"""
i番目まで見て、n個選んでいて、重さがwのときのvの最大値
ただし、wはN個選んだときにW-N*[w[0]]となっているので、そこをmaxとする
dp[i][n][w] 
"""
dp = [[[0]*(3*N+2) for i in range(N+1)] for j in range(N+1)]
dp[0][0][0] = 0
for i,(w,v)  in enumerate(zip(ws_m,vs)):
    for n in range(i+1):
        for j in range(3*N+1):
            # もらうDP
            # j-wなら、新しくwをナップサックに入れて価値が増えるか見る
            if ws[0]*(n+1)+j+w <= W:
                dp[i+1][n+1][j+w] = max(dp[i+1][n+1][j+w], dp[i][n][j]+v)
            # 追加できない場合は以前の情報を更新
                
            dp[i+1][n][j] = max( dp[i+1][n][j], dp[i][n][j] )
            # if dp[i][n][j] == -1: continue
            # # if j + n*ws[0] > W: continue
            # # print("check",i,n,j,v)    )
            # dp[i+1][n][j] = max(dp[i+1][n][j], dp[i][n][j])
            # dp[i+1][n+1][j+w] = max(dp[i][n+1][j+w], dp[i][n][j] + v)
        # print(dp[i+1][n])
ans= 0
for i,As in enumerate(dp[N]):
    w = min( W - i*ws[0], sum_ws_m )
    if w >= 0:
        ans = max(ans,max(As[:w+1]))
print(ans)   