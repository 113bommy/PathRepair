for i in range(int(input())):
  matr = list(map(int, input().split()))
  count = 0
  for j in range(1, matr[0] + 1):
    s = str(input())
    if j < matr[0] + 1:
        if s.endswith('R'):
          count += 1
    else:
      # for k in range(matr[1]):
      for k in range(len(s)):
        if s[k] == 'D':
          count += 1
  print(count)