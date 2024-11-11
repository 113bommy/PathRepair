from collections import deque
dis = [[1, 0], [-1, 0], [0, 1], [0, -1]]
H, W = map(int, input().split())
A = []
count = 0
for i in range(H):
  a = input()
  A.append(a)
  count += a.count(".")
B = [[0 for j in range(W)] for i in range(H)]
D = deque([[0, 0]])
B[0][0] = 1
while len(D) > 0:
  d = D.popleft()
  for k in range(4):
    p = d[0] + dis[k][0]
    q = d[1] + dis[k][1]
    if 0 <= p < H and 0 <= q < W and A[p][q] == "." and B[p][q] == 0:
      B[p][q] = B[d[0]][d[1]] + 1
      D.append([p, q])
if B[H-1][W-1] == 0:
  print(-1)
else:
  print(count - B[H-1][W-1])