import sys
sys.setrecursionlimit(110000)

def dfs(array, current, count):
  array[current - 1] = count
  for neighbour in graph[current]:
    if array[neighbour - 1] == -1:
      array = dfs(array, neighbour, count + 1)
  else:
    return array

T = [-1 for x in range(100000)]
A = [-1 for x in range(100000)]

graph = {}

N,u,v = map(int,input().split())

for i in range(N-1):
  a,b = map(int,input().split())
  try:
    graph[a].append(b)
  except KeyError:
    graph[a] = [b]

  try:
    graph[b].append(a)
  except KeyError:
    graph[b] = [a]

T = dfs(T, u, 0)
A = dfs(A, v, 0)

ans = -1
for i in range(N):
  if T[i+1] < A[i+1]:
    ans = max(ans, A[i+1] - 1)
print(max(0,ans))
