N = int(input())
F = [int(input().replace(" ",""), 2) for _ in range(N)]
P = [list(map(int,input().split())) for _ in range(N)]

ans = -(1e9)
for i in range(1, 2**10):
  b = 0
  for f, p in zip(F, P):
    b += p[bin(f&i).count("1")]
  ans = max(ans, b)
print(ans)