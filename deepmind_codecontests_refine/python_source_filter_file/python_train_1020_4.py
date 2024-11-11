N = int(input())

def dfs(s, res):
  if int(s) > N:
    return
  res = +all((t in s)for t in '753')
  for i in '753':
    res += dfs(s+i, res)
  return res

print(dfs('0', 0))