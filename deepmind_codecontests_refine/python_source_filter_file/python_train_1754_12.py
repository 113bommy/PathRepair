N, A, B, C, D = map(int, input().split())
E = B - A
for m in range(N):
  if C*(N-1-m) - D*m <= E <= -C*m + (N-1-m)*D:
    print("YES")
    break
else
print("NO")