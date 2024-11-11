N = int(input())
gA, sA, bA = map(int, input().split())
gB, sB, bB = map(int, input().split())

#[重さ,価値]を要素とする配列
lstAB_2 = [[gA, gB-gA], [sA, sB-sA], [bA, bB-bA]]
lstBA_2 = [[gB, gA-gB], [sB, sA-sB], [bB, bA-bB]]
lstAB = []
for i in range(3):
    if lstAB_2[i][1] > 0:
        lstAB += [lstAB_2[i]]  

lstBA = []
for i in range(3):
    if lstBA_2[i][1] > 0:
        lstBA += [lstBA_2[i]]

dp = [[0] * (N+1) for _ in range(len(lstAB)+1)]
for i in range(len(lstAB)):
    for j in range(N+1):
        if j < lstAB[i][0]:
            dp[i+1][j] = dp[i][j]
        else:
            dp[i+1][j] = max(dp[i][j], dp[i+1][j-lstAB[i][0]]+lstAB[i][1])

N += dp[len(lstAB)][N]
# print (N)

dp2 = [[0] * (N+1) for _ in range(len(lstBA)+1)]
for i in range(len(lstBA)):
    for j in range(N+1):
        if j < lstBA[i][0]:
            dp2[i+1][j] = dp2[i][j]
        else:
            dp2[i+1][j] = max(dp2[i][j], dp2[i+1][j-lstBA[i][0]]+lstBA[i][1])
print (N + dp2[len(lstBA)][N])
