n=int(input())
l=list(map(int,input().split()))
ones,twos,threes=0,0,0
for i in l:
    if i==1:
        ones+=1
    elif i==2:
        twos+=1
    else:
        threes+=1
max_ones=ones+twos+threes
max_twos=twos+threes
max_threes=threes
dp=[[[0.0]*(n+1)for i in range(n+1)]for j in range(n+1)]
for k in range(max_threes+1):
    for j in range(max_twos+1-k):
        for i in range(max_ones+1-j-k):
            if (i+j+k)==0:
                continue
            else:
                dp[i][j][k]=n/(i+j+k)
                if i>0:
                    dp[i][j][k]+=(dp[i-1][j][k]*i)/(i+j+k)
                if j>0:
                    dp[i][j][k]+=(dp[i+1][j-1][k]*j)/(i+j+k)
                if k>0:
                    dp[i][j][k]+=(dp[i][j+1][k-1]*k)/(i+j+k)
print(dp[i][j][k])




            