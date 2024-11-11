a = int(input())
for i in range(a):
  b = input()
  z = 1
  obs = 1000000000
  for j in range(40):
    x = str(z)
    k = 0
    for m in range(len(b)):
      if b[m] == x[k]:
        k += 1
      if k == len(x):
        break
    obs = min(obs, len(b) - k + len(x) - k)
    z *= 2
  print(obs)