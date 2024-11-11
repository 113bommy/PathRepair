import sys
input = sys.stdin.readline

INF = float('inf')

N = int(input().strip())
data = [list(map(int, input().split())) for _ in range(N)]
cost_b = []
cost_D = []
for b in range(1<<N):
  towns = []
  cost = INF
  for i in range(N):
    if (b>>i)&1:
      towns.append(data[i])
  for i in range(len(towns)):
    X = towns[i][0]
    cost = min(cost,sum(abs(towns[j][0]-X)*towns[j][2] for j in range(len(towns))))
  for i in range(len(towns)):
    Y = towns[i][1]
    cost = min(cost,sum(abs(towns[j][1]-Y)*towns[j][2] for j in range(len(towns))))
  if len(towns) == 0:
    cost = 0
  cost_b.append(cost)
  cost_D.append(sum(min(abs(towns[j][0]),abs(towns[j][1]))*towns[j][2] for j in range(len(towns))))

dp = [[INF]*(N+1) for i in range(1<<N)]

for i in range(1<<N):
  dp[i][0] = cost_D[i]
count = 0
for k in range(1,N+1):
  for i in range(1<<N):
    x = i
    while x>=0:
      x &= i
      new = dp[i-x][k-1]+cost_b[x]
      if dp[i][k] > new:
        dp[i][k] = new
      if new == 0:
        break
      x -= 1
for i in range(N+1):
  print(dp[-1][i])
