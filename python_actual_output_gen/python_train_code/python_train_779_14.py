isDebug = False

n, m = [int(x) for x in input().split()]

r = int(n % 2)
t = int((n/2))
print(f'n={n}, m={m}, t={t}') if isDebug else ''

found = False
a = t
b = r
for i in range(0, t):
  print(f'---\ni={i}, a={a}, b={b}') if isDebug else ''

  if (a+b) % m == 0:
    found = True
    break
  
  a = a - 1
  b = b + 2

print(f'{(a+b) if found else "-1"}')
