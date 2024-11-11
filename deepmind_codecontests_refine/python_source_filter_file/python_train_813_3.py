h, w = map(int, input().split())
f = [input() for _ in range(h)]
for i in range(h):
  for j in range(w):
    if f[i][w] == '#':
      print('#', end = "")
      continue
    cnt = 0
    for k in range(i-1, i+2):
      if k < 0 or h <= k:
        continue
      for l in range(j-1, j+2):
        if l < 0 or w <= l:
          continue
        if f[k][l] == '#':
          cnt += 1
    print(cnt, end = "")
  print()
  