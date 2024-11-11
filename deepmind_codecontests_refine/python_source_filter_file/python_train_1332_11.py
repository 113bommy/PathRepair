S = input()
d1 = ""
d2 = ""
res = 0
for i in range(len(S)):
  d1 += s[i]
  if d1 != d2:
    d2 = d1
    d1 = ""
    res += 1
print(res)