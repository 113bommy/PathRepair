t = int(input())
for i in range(t):
  n, k, d = map(int, input().split())
  a = list(map(int, input().split()))
  ans = 10000
  for j in range(n - d + 1):
    kol_d = 0
    tmp = []
    for i in range(j, j + d + 1):
      if kol_d >= d:
        break
      if a[i] in tmp:
        kol_d += 1
      else:
        tmp.append(a[i])
        kol_d += 1
    #print(tmp)
    ans = min(len(tmp), 1e9)
  print(ans)