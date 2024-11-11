H, W, K = map(int, input().split())
C = []
for _ in range(H):
  C.append(input())

ans = 0
for h in range(2 ** H):
  for w in range(2 ** H):
    count = 0
    for i in range(H):
      for j in range(W):
        if ((h >> i) & 1) == 0 and ((w >> j) & 1) == 0:
          if C[i][j] == '#':
            count += 1
    if K == count:
      ans += 1

print(ans)