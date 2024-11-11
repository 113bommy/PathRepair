def compute():
  from sys import stdin
  [n] = list(map(int, stdin.readline().split()))
  i = list(map(int, stdin.readline().strip()))

  dp = {}
  INF = (int(-1e9),"")

  def f(x,h,m):
    if x >= 2*n:
      return INF

    args = (h,m)
    if args in dp:
      return dp[args]

    res0, res1 = INF, INF
    
    if h>=0:
      ff = f(x+1, h-1,m)
      res0 = (ff[0] + pow(10,h)*i[x], "H"+ff[1])

    if m>=0:
      ff = f(x+1, h,m-1)
      res1 = (ff[0] + pow(10,m)*i[x], "M"+ff[1])    

    dp[args] = res0 if res0[0]>res1[0] else res1
    return dp[args]

  ans = f(0, n-1, n-1)[1]
  print(ans)

if __name__ == "__main__":
  compute()
