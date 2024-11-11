H, W = map(int, input().split())
A = [input() for _ in range(H)]
cnt = 0
for i in range(H):
  cnt += A[i].count("#")
print("Possible" if cnt == H + W - 2 else "Impossible")