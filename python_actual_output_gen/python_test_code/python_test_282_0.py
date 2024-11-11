n, x = map(int, input().split())

a, p = [1], [1]

for i in range(n):
  a.append(a[i] * 2 + 3)
  p.append(p[i] * 2 + 1)

def f(N, X):
  if N == 0:
    if X == 0:
      return 0
    else:
      return 1  
  elif X <= 1 + a[N - 1]:
    return f(N - 1, X - 1)
  else:
    return p[N - 1] + 1 + f(N - 1, X - 2 - a[N - 1])

print(f(n, x))