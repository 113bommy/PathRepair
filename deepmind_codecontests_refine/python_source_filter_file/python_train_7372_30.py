d, g = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(d)]

ans = float('inf')

for i in range(1 << d):
  count = 0
  sum = 0
  nokori = set(range(1, d+1))
  
  for j in range(d):
    if i & (1<<j):
      sum += pc[j][0] * (j+1) * 100 + pc[j][1]
      count += pc[j][0]
      nokori.discard(j+1)
      
  if sum < g:
    use = max(nokori)
    n = min(pc[use-1][0], ((g-sum)//(use*100)))
    count += n
    sum += n*use*100
    
  if sum >= g:
    ans = min(ans, count)

print(ans)