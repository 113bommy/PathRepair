import re
a=['vaporeon','jolteon','flareon','espeon','umbreon','leafeon','glaceon','sylveon']
b=[*open(0)][1][:-1]
for x in a:
  if re.match(b,x):
    print(x)
    break