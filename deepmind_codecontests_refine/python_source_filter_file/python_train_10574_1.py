s = input()
d = {}
c = [0, 0, 0, 0]
for i, item in enumerate(s):
  if c == "!":
    c[item%4] += 1
  else:
    d[item] = i%4
for i in "RBYG":
  print(c[d[i]])
