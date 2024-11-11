import sys
def rec(N,dp,i,j,k):
    if dp[i][j][k]>=0.0:return dp[i][j][k]
    if all([i==0,j==0,k==0]):return 0.0
    res=0.0
    if i>0:res+=rec(N,dp,i-1,j,k)*i
    if j>0:res+=rec(N,dp,i+1,j-1,k)*j
    if k>0:res+=rec(N,dp,i,j+1,k-1)*k
    res=(res+N)*1.0/(i+j+k)
    dp[i][j][k]=res
    return dp[i][j][k]
def main():
    N=int(sys.stdin.readline())
    a=tuple(map(int,sys.stdin.readline().split()))
    n1,n2,n3=a.count(1),a.count(2),a.count(3)
    dp=[[[-1.0 for _ in range(n3+1)] for _ in range(n2+n3+1)] for _ in range(n1+n2+n3+1)]
    print(rec(N,dp,n1,n2,n3))
if __name__=='__main__':main()
