#入力高速化 + 再帰回数制限解除
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10000000)

from bisect import bisect_left,bisect_right
n=int(input())
a=list(map(int,input().split()))
edge=[[]for _ in range(n)]
for _ in range(n-1):
  u,v=map(int,input().split())
  u-=1
  v-=1
  edge[u].append(v)
  edge[v].append(u)
ans=[-1]*n
dp=[10**10]*n

#オイラーツアー
#n=頂点数、s=始点、edge=隣接リスト
#木構造を投げると訪問順listが帰ってくる、|ans|=2*n-1
#適宜書き換えて実装を楽にしましょう
def EulerTour(n,s,e):
  EulerTour_list=[]
  def EulerTour_dfs(i,root):
    EulerTour_list.append(i)
    ind=bisect_right(dp,a[i])
    bef=dp[ind]
    dp[ind]=a[i]
    ans[i]=bisect_left(dp,10**10)
    for j in e[i]:
      if j!=root:
        EulerTour_dfs(j,i)
    if root!=-1:
      EulerTour_list.append(root)
      dp[ind]=bef
  EulerTour_dfs(s,-1)
  return EulerTour_list

EulerTour(n,0,edge)
print(*ans)