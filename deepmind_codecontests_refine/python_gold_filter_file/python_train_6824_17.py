inf = 10**100



n = int(input())


c= list(map(int,input().split()))


t=[]


for i in range(n):
    t.append(input())


re=[i[::-1] for i in t]


dp=[[inf ,inf ] for i in range(n)]

dp[0] =[0,c[0]]
for i in range(1,n):


    if t[i]>=t[i-1]:
        dp[i][0] = min(dp[i][0] , dp[i-1][0])

    if t[i] >= re[i-1]:

        dp[i][0] = min( dp[i][0] , dp[i-1][1])

    if re[i]>= t[i-1]:
        dp[i][1] = min(dp[i][1] , dp[i-1][0]+c[i])

    if re[i] >= re[i-1]:
        dp[i][1] = min(dp[i][1] , dp[i-1][1]+c[i])


if min(dp[-1])==inf:
    print(-1)
else:
    print(min(dp[-1]))
