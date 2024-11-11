e = input()
op = ("+", "-")
for i in range(6):
  t = ""
  for j in range(4):
    k = i>>j&1
    t += e[j]+op[k]
  t = t[:-1:]
  if eval(t)==7:
    print(t+"=7")
    break