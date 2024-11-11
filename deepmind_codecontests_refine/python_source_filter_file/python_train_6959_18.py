n, m = int(input()), 0
for i in range(1, n**.5 + 1):
  if n%i == 0:
    m = max(m, i)
print(len(str(n // m)))