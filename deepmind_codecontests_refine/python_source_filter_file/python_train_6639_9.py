N=int(input())
A=sorted(map(int,input().split()))
dp=[1]*10**6
for a in A:
    if dp[a-1]==1:
        dp[a-1]=2
        for i in range(a*2,10**6,a):
            dp[i-1]=0
    elif dp[a-1]==2:
        dp[a-1]=0
print(sum([1 for a in A if dp[a-1]]))