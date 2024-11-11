mod = (10 ** 9 + 7)
tot = 1
l = [1, 0, 0]
for i in range(3, 2000):
  nex = (tot - l[-1] - l[-2]) % mod
  tot = (tot + nex) % mod
  l.append(nex)
print(l[int(input())])
