N = int(input())

for h in range(1, 3501):
  for n in range(1, 3501):
    a = (4 * h * n) - N * h - N * n
    if a == 0:
      continue
    w = (N * h * n) / a
    if w.is_integer() and 0 < w:
      print(h, n, int(w))
      exit(0)