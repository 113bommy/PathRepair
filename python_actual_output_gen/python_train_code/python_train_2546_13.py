D,G = map(int,input().split())
P = []
num_p = 0
for i in range(1,D+1):
    p,c = map(int,input().split())
    num_p += p
    for j in range(1,p+1):
        P += [(j,i*100*j+c*(j==p))]
dp = [0]*(num_p+1)
for k,pt in P:
    if k==1:
        t_dp = dp[:]
    for cur in range(1,num_p+1):
        if cur>=k:
            dp[cur] = max(dp[cur], t_dp[cur-k] + pt)
for i in range(num_p):
    if dp[i]>=G:
        print(i)
        break