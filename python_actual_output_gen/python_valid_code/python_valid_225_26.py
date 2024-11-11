O = input()
E = input()

s=''
for i in range(len(O)):
  s += O[i]
  if i < len(E):
    s+= E[i]
