N, M = map(int, input().split())
xyz = [list(map(int, input().split())) for _ in range(N)]
ans = 0
for i in (-1, 1):
  for j in (-1, 1):
    for k in (-1, 1):
      maxp = []
      for p in xyz:
        maxp.append(i * p[0] + j * p[1] + k * p[2])
      maxp.sort(reverse=True)
      aa = sum(maxp[:M])
      if ans <= aa:
        ans = aa
print(ans)
