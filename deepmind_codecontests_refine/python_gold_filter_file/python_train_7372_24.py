d, g = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(d)]
ans = []
def dfs(i, sum, count, residue):
  if i == d:
    if sum < g:
      use = max(residue)
      n = min(pc[use - 1][0], -(-(g - sum)//(use*100)))
      count += n
      sum +=  n*use*100
    if sum >= g:
      ans.append(count)
  else:
    dfs(i + 1, sum, count, residue)
    dfs(i + 1, sum + pc[i][0]*(i + 1)*100 + pc[i][1], count + pc[i][0], residue - {i+1})

dfs(0, 0, 0, set(range(1, d+1)))
print(min(ans))