def Warshall_Floyd(edges,N):
  for k in range(N):
    for i in range(N):
      for j in range(N):
        edges[i][j]=min(edges[i][j],edges[i][k]+edges[k][j])
  return edges
 
import itertools
N, M, R = map(int,input().split())
r = list(map(int,input().split()))
A=[[float("inf") for i in range(N)] for j in range(N)]
for m in range(M):
  a, b, c = map(int,input().split())
  A[a-1][b-1] = c
  A[b-1][a-1] = c
A = Warshall_Floyd(A,N)
 
ans = float("inf")
for road in list(itertools.permutations(r)):
  length = 0
  for i in range(R-1):
    length += A[road[i]-1][road[i+1]-1]
  ans = min(ans, length)
print(ans)