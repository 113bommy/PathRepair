I = lambda s:map(int, s)

p = int(input().split()[1])
s = input()
if 10 % p == 0:
  r = sum(i for i, x in enumerate(I(s), 1) if x % p == 0)
else:
  d = [1] + [0] * (p - 1)
  t, y = 0, 1
  for i, x in enumerate(I(reversed(s)), 1):
    t = (t + x * y) % p
    d[t] += 1
    y = y * 10 % p;
  r = sum(i * (i - 1) // 2 for i in d)
print(r)
