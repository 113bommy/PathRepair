H, W=map(int, input().split())
maxK=81
A=[list(map(int, input().split())) for _ in range(H)]
B=[list(map(int, input().split())) for _ in range(H)]
C=[[abs(A[i][j]-B[i][j]) for j in range(W)] for i in range(H)]
dp=[[[0 for _ in range(maxK+1)] for _ in range(W+1)] for _ in range(H+1)]
dp[1][1][C[0][0]]=1
for i in range(1, H+1):
    for j in range(1, W+1):
        for k in range(maxK):
            if dp[i-1][j][k]==1 or dp[i][j-1][k]==1:
                k_candidate1, k_candidate2=abs(k-C[i-1][j-1]), abs(k+C[i-1][j-1])
                if k_candidate1<maxK:
                    dp[i][j][k_candidate1]=1
                if k_candidate2<maxK:
                    dp[i][j][k_candidate2]=1
for k in range(maxK):
    if dp[H][W][k]==1:
        print(k)
        break