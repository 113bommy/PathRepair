INF = 10 ** 10
while True:
  n = int(input())
  if n == 0:
    break

  costs = [[INF] * 10 for _ in range(10)]
  for i in range(10):
    costs[i][i] = 0
  
  city = set()
  for _ in range(n):
    a, b, c = map(int, input().split())
    city = city | {a, b}
    costs[a][b] = c
    costs[b][a] = c 
  
  city = sorted(list(city))
  
  for i in range(10):
    for j in range(10):
      for k in range(10):
        costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])
  
  min_total = INF
  best_city = -1
  for fr in city:
    total = 0
    for to in city:
      total += costs[fr][to]
    if total < min_total:
      min_total = total
      best_city = fr
  print(best_city, min_total)
