n, m = map(int, input().split())
a = []
imin, imax = m - 1, 0
jmin, jmax = n - 1, 0
for i in range(n):
  s = input()
  a.append(s)
  for j in range(m):
    if s[j] == '*':
      imin = min(imin, i)
      imax = max(imax, i)
      jmin = min(jmin, j)
      jmax = max(jmax, j)
 
for i in range(imin, imax + 1):
  print(a[i][jmin:jmax+1])