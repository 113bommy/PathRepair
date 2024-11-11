H, W = map(int, input().split())
state = [list(map(str, input().split())) for _ in range(H)]

A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for h in range(H):
  for w in range(W):
    if state[h][w] == 'snuke':
      ans = A[w] + str(h+1)
print(ans)
