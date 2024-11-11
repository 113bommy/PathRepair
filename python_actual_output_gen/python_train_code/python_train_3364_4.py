A, B, K = map(int,input().split())
for i in range(K):
  if K % 2 == 0:
    A = A // 2
    B += A
  else:
    B = B // 2
    A += B
print(int(A), int(B))
