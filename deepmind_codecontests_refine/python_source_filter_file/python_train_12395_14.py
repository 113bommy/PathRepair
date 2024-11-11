while:
  a = list(map(int, input().split()))
  if sum(a) == 0:
    break
  print(' '.join.(list(map(str, sorted(a)))))