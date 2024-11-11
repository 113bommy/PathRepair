h,w,d = map(int, input().split())

dp= [0]*(h*w+1)

ab = [list(map(int, input().split())) for _ in range(h)]

for i in range(w):
    for j in range(h):
        s = ab[i][j]
        dp[s] =[i,j]
        
dpp= [0]*(h*w+1)

for k in range(d+1,h*w+1):
#    print(k)
    dpp[k] = dpp[k-d] + abs(dp[k][0]-dp[k-d][0]) +abs(dp[k][1]-dp[k-d][1])
    
q = int(input())

for x in range(q):
    a,b = map(int, input().split())
    print(dpp[b]-dpp[a])