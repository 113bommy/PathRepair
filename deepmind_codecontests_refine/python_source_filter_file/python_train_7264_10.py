import heapq

mod = 998244353

n = int(input())
robot = [tuple(map(int, input().split())) for _ in range(n)]
robot.sort(reverse=True)
parent = list(range(n))

root = []
for i in range(n):
  x, d = robot[i]
  while root:
    r = heapq.heappop(root)
    if r[0] < x + d:
      parent[r[1]] = i
    else:
      heapq.heappush(root, r)
      break
  heapq.heappush(root, (x, i))
  
count = 1
dp = [1] * n
for i in range(n):
  p = parent[i]
  if p == i:
    count = count * dp[i] % mod
  else:
    dp[p] = dp[p] * (dp[i] + 1) % mod
print(count)