N = int(input())
C = [int(input()) for _ in range(N)]
C = [x for (x,y) in zip(C[:-1], C[1:]) if x!=y] + [C[-1]]

SUM = 1
DP_dict = {}

for c in C:
  if c in DP_dict.keys():
    SUM += DP_dict[c] = SUM
  DP_dict[c] = SUM

print(SUM % (10**9+7))