N = int(input())
for h in range(3500):
  for n in range(n):
    try:w = (N*h*n) / (4*n*h - N*n - N*h)
    except ZeroDivisionError: continue
    if w>0 and w.is_integer():
      print(h, n, int(w))
      exit()