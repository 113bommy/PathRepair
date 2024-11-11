p = int(input().split()[1])
s = input()
if 10 % p == 0:
  r = sum(i for i, x in enumerate(s, 1) if int(x) % p == 0)
else:
  d = [1] + [0] * (p - 1)
  t, y = 0, 1
  for x in reversed(s):
    t = (t + int(x) * y) % p
    d[t] += 1
    y = y * 10 % p;
  r = sum(i * i - i for i in d) // 2
print(r)