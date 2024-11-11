import sys
input = sys.stdin.readline
n = int(input())
stone = [0]+list(map(int,input().split()))
ab = [list(map(int,input().split())) for i in range(n-1)]
graph = [[] for i in range(n+1)]
dp = [[] for i in range(n+1)]
deg = [0]*(n+1)
stack = []
for a,b in ab:
  graph[a].append(b)
  graph[b].append(a)
  deg[a] += 1
  deg[b] += 1
root = 0
for i in range(1,n+1):
  if deg[i] == 1:
    stack.append(i)
  elif root == 0:
    root = i
if root == 0:
  if stone[1] == stone[2]:
    print("YES")
  else:
    print("NO")
  exit()
deg[root] += 1
flg = 1
while stack:
  x = stack.pop()
  if x == root:
    if sum(dp[x]) != 2*stone[x] or max(dp[x]) > stone[x]:
      flg = 0
    break
  elif dp[x]:
    if max(max(dp[x])*2,sum(dp[x])) > stone[x]*2 or stone[x] > sum(dp[x]):
      flg = 0
      break
    stone[x] = 2*stone[x]-sum(dp[x])
  for y in graph[x]:
    if deg[y] > 1:
      dp[y].append(stone[x])
      deg[y] -= 1
      if deg[y] == 1:
        stack.append(y)
if flg:
  print("YES")
else:
  print("NO")