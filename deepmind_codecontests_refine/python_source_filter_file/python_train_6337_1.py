while True:
  n,m = input().split()
  n = int(n)
  m = int(m)
  if n==m==0:
    break
  l = [i for i in range(n)]
  c = 0
  while len(l) >= 2:
    c = (c+m)%len(l)
    l.pop(c)
    c -= 1
  print(l[0])