from collections import deque

H, W = map(int, input().split())
m = [list(input()) for i in range(H)]
ans = 0
q = deque()

for h in range(H):
  for w in range(W):
    if m[h][w] == "#":
      q.append((h, w, 0))

while q:
  h, w, c = q.popleft()
  ans = max(ans, c)
  for dh, dw in ((-1, 0), (1, 0), (0, -1), (0, 1)):
    if 0 <= h+dh < H and 0 <= w+dw < W and m[h + dh][w + dw] == ".":
      m[h + dh][w + dw] = "#"
      q.append((h+dh, w+dw, c+1))

print(ans)