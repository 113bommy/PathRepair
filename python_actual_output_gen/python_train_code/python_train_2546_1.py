D, G = map(int, input().split())
PC = [0] + [list(map(int, input().split())) for _ in range(D)]
def dfs(i, g):
  if i == 0:
    return 1e9
  mc = min(G // (100 * i), PC[i][0])
  s = mc * 100 * i
  if mc == PC[i][0]:
    s += PC[i][1]
  if s < g:
    mc += dfs(i - 1, g - s)
  return min(dfs(i - 1, g), mc)
print(dfs(D, G))