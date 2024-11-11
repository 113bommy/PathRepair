import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
def main():
  MOD = 10**9+7
  N = int(input())
  edge = [[] for _ in range(N+1)]
  dp = [[0]*2 for i in range(100005)]
  # dp[v][c]: 頂点vを色cの根とする部分木の塗り分け方の総数
  # 葉が決まると順々に求まっていく
  for i in range(N-1):
      x,y = map(int,input().split())
      edge[x].append(y)
      edge[y].append(x)

  # 0:white,1:black
  def dfs(v,last=-1):
      dp[v][0] = 1
      dp[v][1] = 1
      for nv in edge[v]:
          if nv == last:
              continue
          dfs(nv, v)
          dp[v][0] = dp[v][0] * ((dp[nv][0] + dp[nv][1]) % MOD) % MOD
          dp[v][1] = dp[v][1] * dp[nv][0] % MOD


  dfs(1)
  print((dp[1][0] + dp[1][1])%MOD)
if __name__ == '__main__':
  main()