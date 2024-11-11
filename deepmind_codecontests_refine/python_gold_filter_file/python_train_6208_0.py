a = list(map(int, input().split()))
if sum(a) % 2 == 1:
  print('NO')
else:
  target = sum(a) // 2
  n = 6
  ans = 'NO'
  for i in range(n):
    for j in range(i + 1, n):
      for k in range(j + 1, n):
        if a[i] + a[j] + a[k] == target:
          ans = 'YES'
  print(ans)