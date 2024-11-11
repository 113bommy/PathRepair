N,M=map(int,input().split())
A=list(map(int,input().split()))
B=[2,5,5,4,5,6,3,7,6]


dp=[0]*(N+1)
for j in range(M):
    need=B[A[j]-1]
    dp[need]=max(dp[need],A[j])

for i in range(1,N+1):
    for j in range(M):
        need=B[A[j]-1]
        if i-need>=0:
            if dp[i-need]:
                dp[i]=max(dp[i], dp[i-need]*10+dp[need])
            
print(dp[-1])

