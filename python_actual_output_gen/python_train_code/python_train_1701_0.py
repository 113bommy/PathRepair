t = int(input())

for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  cnt = 0
  
  for i in range(n):
    aj = 1
    while (True):
      j = aj * a[i] - (i + 1)
      if (j > n):
        break
      if (j <= i):
        aj += 1
        continue
      if (a[j - 1] == aj):
        cnt += 1
      aj += 1
  print(cnt)
