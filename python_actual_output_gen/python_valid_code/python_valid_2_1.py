N, M, C = map(int, input().split())
B = [int(i) for i in input().split()]
ans = 0
for _ in range(N):
  A = [B[i] * int(j) for i,j in enumerate(input().split())]
  ans += 1 if sum(A) > 0 else 0
print(ans)