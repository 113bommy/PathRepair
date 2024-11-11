import sys
sys.setrecursionlimit(1e6)

N, M = map(int, input().split())
if M % 2 == 1:
  print(-1)
  exit()
  
E = []
A = [[] for _ in range(N)]
for _ in range(M):
  i, j = map(int, input().split())
  E.append([i-1, j-1])
  A[i-1].append(j-1)
  A[j-1].append(i-1)

tree = [[] for _ in range(N)]
visited = [False] * N
queue = [0]
visited[0] = True
while queue:
  i = queue.pop()
  for j in A[i]:
    if not visited[j]:
      tree[i].append(j)
      tree[j].append(i)
      visited[j] = True
      queue.append(j)

D = [0] * N
for i, j in E:
  if i not in tree[j]:
    print(i+1, j+1)
    D[i] += 1

def f(parent, i):
  for j in tree[i]:
    if j == parent:
      continue
    f(i, j)
    if D[j] % 2 == 0:
      print(i+1, j+1)
      D[i] += 1
    else:
      print(j+1, i+1)
      D[j] += 1
  return

f(0, 0)
