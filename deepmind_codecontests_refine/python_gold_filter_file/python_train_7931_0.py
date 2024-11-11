t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  a.sort()
  found = False
  for i in range(1, n):
    if a[i] - a[i - 1] == 1:
      found = True
      break
  if found:
    print(2)
  else:
    print(1)