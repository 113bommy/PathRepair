n,x=map(int, input().split())
A=list(map(int,input().split()))
DP=[[0]*3 for _ in range(n+1)]
ans=0
for i in range(1,n+1):
    DP[i][0]=max(DP[i-1][0]+A[i-1],A[i-1])
    DP[i][1]=max(DP[i-1][0]+A[i-1]*x,DP[i-1][1]+A[i-1]*x,A[i-1]*x)
    DP[i][2]=max(DP[i-1][1]+A[i-1]*x,DP[i-1][2]+A[i-1]*x,A[i-1])
    ans=max(ans,max(DP[i]))
print(ans)