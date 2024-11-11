import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 9)

def main():
  N = int(input())
  XY = [tuple(map(int,input().split())) for _ in range(N-1)]
  MOD =10**9+7
  
  E = [[] for _ in range(N)]
  for x,y in XY:
    x -= 1
    y -= 1
    E[x].append(y)
    E[y].append(x)
  
  def dfs(v,s):
    b = 1
    w = 1
    for u in E[v]:
      if u != s:
        b0,w0 = dfs(u,v)
        b *= w0
        w *= (b0+w0)
    #b %= MOD
    #w %= MOD
    return b,w

  b,w = dfs(0,-1)
  print((b+w) % MOD)

if __name__ == '__main__':
    main()
