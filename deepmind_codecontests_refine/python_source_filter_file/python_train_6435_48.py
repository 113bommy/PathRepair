import math,itertools,fractions,heapq,collections,bisect,sys,queue,copy

sys.setrecursionlimit(10**7)
inf=10**20
mod=1000000007
dd=[(-1,0),(0,1),(1,0),(0,-1)]
ddn=[(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return input()

def main():
  s=S()
  n=len(s)
  _d=I()


  dp=[[[0]*(_d+1) for _ in range(2)]for __ in range(n+1)]
  dp[0][0][0]=1

  for i in range(n):
    nd=int(s[i])
    for j in range(2):
      for k in range(_d):
        for d in range(10):

          ni=i+1
          nj=j
          nk=k

          if nj==0:
            if d>nd:
              continue
            if d<nd:
              nj=1

          nk+=d
          nk%=_d

          dp[ni][nj][nk]+=dp[i][j][k]
          dp[ni][nj][nk]%=mod

  return (dp[n][0][0]+dp[n][1][0])%mod-1

# main()
print(main())
