_, a = open(0)
mod = 10**9+7
c = 1
l = [3] + [0]*10**6

for a in a.split():
  a = int(a)
  c = c * l[a] % mod
  d[a] -= 1
  d[a] += 1
print(c)