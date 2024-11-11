n=int(input())
A=[int(i) for i in input().split()]
B=[int(i) for i in input().split()]
DP=[[0]*n for _ in range(2)]
DP[0][0]=A[0]
DP[1][0]=B[0]
for i in range(1,n):
  DP[0][i]=max(A[i]+DP[1][i-1],DP[0][i-1])
  DP[1][i]=max(B[i]+DP[0][i-1],DP[1][i-1])
print(max(DP[0][n-1],DP[1][n-1]))