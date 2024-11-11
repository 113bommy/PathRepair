H, W = map(int,input().split())
A = [list(map(int,input().split())) for i in range(H)]
n = 0
memo = []

for x in range(W):
  for y in range(H-1):
    if A[y][x]%2 == 1:
      A[y][x] -= 1
      A[y+1][x] += 1
      n += 1
      memo.append([y+1,x+1,y+2,x+1])
for x in range(W):
  if A[H-1][x]%2 == 1:
    A[H-1][x] -= 1
    A[H-1][x+1] += 1
    memo.append([H,x+1,H,x+2])
    n += 1
print(n)
for i in range(n):
  print(" ".join(map(str,memo[i])))