n=int(input())
arr=list(map(int,input().split()))
one=two=three=0
for i in arr:
    if i==1:
        one+=1
    elif i==2:
        two+=1
    elif i==3:
        three+=1
max_one=one+two+three
max_two=two+three
max_three=three
dp=[[[0.0]*(n+1) for i in range(n+1)] for j in range(n+1)]
for k in range(max_three+1):
    for j in range(max_two+1-k):
        for i in range(max_one+1-j-k):
            if i+j+k==0:
                continue
            else:
                dp[i][j][k]=n/(i+j+k)
            if i>0:
                dp[i][j][k] += (dp[i-1][j][k]*i)/(i+j+k)
            if j>0:
                dp[i][j][k] += (dp[i+1][j-1][k]*j)/(i+j+k)
            if k>0:
                dp[i][j][k] += (dp[i][j+1][k-1]*k)/(i+j+k)
print(dp[i][j][k])
    
    