S = input()
S = S + '0'
mod = 2019
p = [0] * mod
r = 0
d = 1
for s in reversed(S):
  t = int(s)%mod
  r += t*d
  r %= mod
  d = d*10
  p[r] += 1

print(sum([i*(i-1)//2 for i in p]))