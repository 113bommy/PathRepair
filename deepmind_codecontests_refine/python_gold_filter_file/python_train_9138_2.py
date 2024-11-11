N=int(input())
g=[[] for i in range(N)] 
cnt=0
for i in range(N):
  s=input()
  for j in range(N):
    if s[j]=='1':
      g[i].append(j)
      cnt+=1
w=cnt//2

color=[0]*N #color[i]:点iの色(1 or -1)。但し塗られていないときは0とする

def f(v,c):
    #頂点vに隣接する頂点全てを塗るあるいは判定する
    color[v] = c
    for i in range(len(g[v])):
        if color[g[v][i]]==c:
            return False
        elif color[g[v][i]]==0 and not f(g[v][i],-c):
            #(g[v][i]がまだ塗られていない　かつ　そこを-cで塗っても問題ない) ではないなら
            return False
    return True

def warshall(d,n):
  for k in range(n):
    for i in range(n):
      for j in range(n):
        d[i][j]=min(d[i][j],d[i][k]+d[k][j])
  return d

k=1
for i in range(N):
  if color[i]==0:
    if not f(i,1):
      k=-1

if k==-1:
  print(-1)
else:
  d=[[float('inf')]*N for i in range(N)]
  for i in range(N):
    for j in g[i]:
      d[i][j]=1
  for i in range(N):
    d[i][i]=0
  A=warshall(d,N)
  ans=0
  for i in range(N):
    for j in range(N):
      ans=max(ans,d[i][j])
  print(ans+1)