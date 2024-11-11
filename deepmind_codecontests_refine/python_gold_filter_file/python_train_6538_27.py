H, W = map(int, input().split())
A = []
q = []
for i in range(H):
  As = list(input())
  A.append(As)
  for j in range(W):
    if A[i][j] == "#":
      q.append((i, j))
r = 0
while q:
  q2 = []
  for i, j in q:
    if i-1 >= 0 and A[i-1][j] == ".":
      A[i-1][j] = "#"
      q2.append((i-1, j))
    if i+1 < H and A[i+1][j] == ".":
      A[i+1][j] = "#"
      q2.append((i+1, j))
    if j-1 >= 0 and A[i][j-1] == ".":
      A[i][j-1] = "#"
      q2.append((i, j-1))
    if j+1 < W and A[i][j+1] == ".":
      A[i][j+1] = "#"
      q2.append((i, j+1))
  q = q2
  r += 1
r -= 1
print(r)
