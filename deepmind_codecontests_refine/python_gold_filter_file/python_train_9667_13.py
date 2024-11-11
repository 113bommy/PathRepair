H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

ans = 0
for i in range(H):
  ans += A[i].count("#")
print("Possible" if ans == H + W - 1  else "Impossible")