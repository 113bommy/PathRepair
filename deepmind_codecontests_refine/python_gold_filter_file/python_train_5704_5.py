H, W = map(int, input().split())

memo = [[10**5]*W for _ in range(H)]
mp = [input() for _ in range(H)]

if mp[0][0] == '#':
  memo[0][0] = 1
else:
  memo[0][0] = 0

for i in range(H):
  for j in range(W):
    if i > 0:
      if mp[i-1][j] == '.' and mp[i][j] == '#':
        memo[i][j] = min(memo[i][j],memo[i-1][j]+1)
      else:
        memo[i][j] = min(memo[i][j],memo[i-1][j])
    if j > 0:
      if mp[i][j-1] == '.' and mp[i][j] == '#':
        memo[i][j] = min(memo[i][j],memo[i][j-1]+1)
      else:
        memo[i][j] = min(memo[i][j],memo[i][j-1])
        
print(memo[-1][-1])