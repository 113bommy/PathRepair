h, w = map(int, input().split())
a = [input() for i in range(h)]
for i in range(h):
  b = ""
  for j in range(w):
    if a[i][j] == "#":
      b += "#"
    else:
      b += str(sum(k[max(0, j-1):min(w, j+2)].count("#") for k in a[max(0, i-1):min(h, j+2)]))
  print(b)