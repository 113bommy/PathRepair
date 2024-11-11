n, m, d = map(int, input().split())
E = 0
if d:
  E =2 * (n - d)
else:
  E = n
print(E * (m - 1) / n)