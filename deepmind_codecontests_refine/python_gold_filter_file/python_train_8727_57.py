N = int(input())

if N%2 == 0:
  print(N, N, N//2)
else:
  for h in range(1, 3501):
    for n in range(1, 3501):
      num = N*h*n
      dem = 4*h*n - N*(h+n)
      if dem > 0 and num%dem == 0:
        print(h, n, num//dem)
        quit()