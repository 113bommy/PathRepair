n = int(input())

a = []

def ms(x):
  x = str(x)
  v = 0
  for i in x:
    v += int(i)
  return v

for i in range(n, max(n-111, 0), -1):
  if i + ms(i) == n:
    a.append(i)

print(len(a))
for i in a:
  print(i)