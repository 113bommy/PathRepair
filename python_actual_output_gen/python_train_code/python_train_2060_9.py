w = input()
count = 0
for i in w:
  nw = w.replace(i,"")
  c = len(w) - len(nw)
  count += int(c)**2
  if len(nw) == 0:
    break
print(count)
