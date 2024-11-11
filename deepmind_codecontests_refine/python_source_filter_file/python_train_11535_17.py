#https://atcoder.jp/contests/abc147/submissions/8874645
import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
input=lambda:sys.stdin.readline().rstrip()
def resolve():
    ofs=6400
    h,w=map(int,input().split())
    A=[list(map(int,input().split())) for _ in range(h)]
    B=[list(map(int,input().split())) for _ in range(h)]
    dp=[[0]*w for _ in range(h)]
    x=abs(A[0][0]-B[0][0])
    dp[0][0]|=(1<<(ofs+x))|(1<<(ofs-x))

    from itertools import product
    for i,j in product(range(h),range(w)):
        x=abs(A[i][j]-B[i][j])
        t=0
        if(i-1>=0):
            t|=dp[i-1][j]
        if(j-1>=0):
            t|=dp[i][j-1]
        dp[i][j]=(t<<x)|(t>>x)

    for i,s in enumerate(bin(dp[-1][-1])[-ofs-1:]):
        if(s=='1'):
            print(i)
            return
                    
resolve()
