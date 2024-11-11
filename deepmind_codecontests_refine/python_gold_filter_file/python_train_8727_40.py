N = int(input())
for h in range(1, 3500):
  for n in range(1, 3500):
    a = N*h*n
    b = 4*h*n - n*N - N*h
    if b > 0 and a%b == 0:
      print(h, n, a//b)
      exit()