H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
X = [[-10**2 for __ in range(W)] for _ in range(H)]
Y = [[-10**2 for __ in range(W)] for _ in range(H)]
for y in range(H):
  last_x = -1
  for x in range(W):
    if S[y][x] == "#":
      for t in range(last_x+1,x):
        X[y][t] = x-1-last_x
      last_x = x
  for t in range(last_x+1,W):
    X[y][t] = W-1-last_x
for x in range(W):
  last_y = -1
  for y in range(H):
    if S[y][x] == "#":
      for t in range(last_y+1,y):
        Y[t][x] = y-1-last_y
      last_y = y
  for t in range(last_y+1,H):
    Y[t][x] = H-1-last_y
ans = 0
for y in range(H):
  for x in range(W):
    ans = max(ans, Y[y][x]+X[y][x])
print(ans-1)
