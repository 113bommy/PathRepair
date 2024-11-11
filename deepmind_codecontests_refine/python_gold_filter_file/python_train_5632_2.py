n, m = map(int, input().split())
a = (map(int,input().split()))
di = {}
for i in a:
  if i not in di:
    di[i] = 1
  else:
    di[i] += 1
for d in range(100, 0, -1):
  k = 0
  dic = di.copy()
  for i in di.keys():
    while dic[i] >= d:
      dic[i] -= d
      k += 1
  if k >= n:
    print(d)
    exit()
print(0)
