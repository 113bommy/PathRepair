import sys
input = sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))

A=a.count(1)
B=a.count(2)
C=a.count(3)

dp=[[[0]*(n+1) for _ in range(n+1)] for _ in range(n+1)]
def c():
    for k in range(C+1):
        for j in range(B+C+1-k):
            for i in range(n+1-k-j):
                if i==0 and j==0 and k==0:
                    continue
                res=1.0*n
                if i>0:
                    res+=i*dp[i-1][j][k]
                if j>0:
                    res+=j*dp[i+1][j-1][k]
                if k>0:
                    res+=k*dp[i][j+1][k-1]
                dp[i][j][k]=res/(i+j+k)
    print(dp[A][B][C])
c()