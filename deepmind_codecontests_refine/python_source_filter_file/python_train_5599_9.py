def main()
  def dfs(x):
    m=x//2
    if m not in dp or dp[m]>dp[x]+abs(2*m-x)*d+a:
      dp[m]=dp[x]+abs(2*m-x)*d+a
      dfs(m)
    m=0--x//2
    if m not in dp or dp[m]>dp[x]+abs(2*m-x)*d+a:
      dp[m]=dp[x]+abs(2*m-x)*d+a
      dfs(m)
    m=x//3
    if m not in dp or dp[m]>dp[x]+abs(3*m-x)*d+b:
      dp[m]=dp[x]+abs(3*m-x)*d+b
      dfs(m)
    m=0--x//3
    if m not in dp or dp[m]>dp[x]+abs(3*m-x)*d+b:
      dp[m]=dp[x]+abs(3*m-x)*d+b
      dfs(m)
    m=x//5
    if m not in dp or dp[m]>dp[x]+abs(5*m-x)*d+c:
      dp[m]=dp[x]+abs(5*m-x)*d+c
      dfs(m)
    m=0--x//5
    if m not in dp or dp[m]>dp[x]+abs(5*m-x)*d+c:
      dp[m]=dp[x]+abs(5*m-x)*d+c
      dfs(m)
  def solve():
    dp[n]=0
    dfs(n)
    return min(dp[i]+abs(i)*d for i in dp)
  for _ in range(int(input())):
    n,a,b,c,d=map(int,input().split())
    dp={}
    print(solve())
if __name__ == "__main__":
  main()