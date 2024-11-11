n = int(input())
for i in range(1, 3501):
  for j in range(1, 3501):
    seed = 4 * i * j - n * i - n * j 
    if seed > 0:
      k = n * i * j / seed 
      if k % 1 == 0:
        print(i, j, int(k))
        exit()
