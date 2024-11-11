import sys
sys.setrecursionlimit(10**7)
def main(n,ki,uv):
  # n: 頂点数
  # ki: 木
  # Euler Tour の構築
  S=[] # Euler Tour
  F=[0]*n # F[v]:vにはじめて訪れるステップ
  depth=[0]*n # 0を根としたときの深さ
  def dfs(v,pare,d):
      F[v]=len(S)
      depth[v]=d
      S.append(v)
      for i,w in ki[v]:
          if w==pare:continue
          dfs(w,v,d+1)
          S.append(v)
  dfs(0,-1,0)
  # Sをセグメント木に乗せる
  # u,vのLCAを求める:S[F[u]:F[v]+1]のなかでdepthが最小の頂点を探せば良い
  # F[u]:uに初めてたどるつくステップ
  # S[F[u]:F[v]+1]:はじめてuにたどり着いてつぎにvにたどるつくまでに訪れる頂点
  # 存在しない範囲は深さが他よりも大きくなるようにする
  INF = (n, None)
  # LCAを計算するクエリの前計算
  M = 2*n
  M0 = 2**(M-1).bit_length() # M以上で最小の2のべき乗
  data = [INF]*(2*M0)
  for i, v in enumerate(S):
    data[M0-1+i] = (depth[v], i)
  for i in range(M0-2, -1, -1):
    data[i] = min(data[2*i+1], data[2*i+2])
  # LCAの計算 (generatorで最小値を求める)
  def _query(a, b):
    yield INF
    a += M0; b += M0
    while a < b:
      if b & 1:
        b -= 1
        yield data[b-1]
      if a & 1:
        yield data[a-1]
        a += 1
      a >>= 1; b >>= 1
  # LCAの計算 (外から呼び出す関数)
  def query(u, v):
    fu = F[u]; fv = F[v]
    if fu > fv:
      fu, fv = fv, fu
    return S[min(_query(fu, fv+1))[1]]
  

  todo=[[0,[]]]
  path=[[]]*n
  mi=[1]*n
  while todo:
    v,ary=todo.pop()
    path[v]=ary
    mi[v]=0
    for i,nv in ki[v]:
      if mi[nv]==1:
        todo.append([nv,ary+[i]])
        mi[nv]=1
  #print(path)
  for i in range(n):
    path[i]=set(path[i])
  memo={}
  ans=0
  for i in range(2**m):
    chk=set(())
    for j in range(m):
      if (i>>j)&1:
        chk.add(j)
    must_w=set(())
    for c in chk:
      if c in memo:
        tmp=memo[c]
      else:
        u,v=uv[c]
        dd=query(u,v)
        tmp=path[u].union(path[v])
        tmp=tmp-path[dd]
        memo[(u,v)]=tmp
      must_w=must_w.union(tmp)
    t=n-1-len(must_w)
    if len(chk)%2==1:
      ans-=pow(2,t)
    else:
      ans+=pow(2,t)
  print(ans)
if __name__=='__main__':
  n=int(input())
  ki=[[] for _ in range(n)]
  for i in range(n-1):
    u,v=map(int,input().split())
    u,v=u-1,v-1
    ki[u].append([i,v])
    ki[v].append([i,u])
  m=int(input())
  uv=[]
  for _ in range(m):
    u,v=map(int,input().split())
    u,v=u-1,v-1
    uv.append([u,v])
  main(n,ki,uv)
