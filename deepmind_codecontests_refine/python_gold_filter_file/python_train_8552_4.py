if __name__ == '__main__':
  n = int(input())
  a = [int(x) for x in input().split(' ')]
  s = 0
  for x in a:
    s += x
  if s % 2 == 1:
    print(" ".join([str(x) for x in a]))
  else:
    a.sort()
    s1 = 0
    for x in range(len(a) // 2):
      s1 += a[x]
    if s1 == s // 2:
      print(-1)
    else:
      print(" ".join([str(x) for x in a]))