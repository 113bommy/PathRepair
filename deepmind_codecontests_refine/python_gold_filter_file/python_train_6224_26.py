d = {0: 1}
s, p = 0, 1
for c in reversed(input()):
  s = (s + p * int(c)) % 2019
  d[s] = d.get(s, 0) + 1
  p = p * 10 % 2019
print(sum(x * (x - 1) // 2 for x in d.values()))
