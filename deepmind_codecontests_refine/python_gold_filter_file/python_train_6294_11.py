from sys import exit as ex
d = {'A':0,'B':0,'C':0}
for _ in range(3):
  s = input()
  if s[0] == s[2]:
    print("impossible")
    ex()
  if s[1] == '>':
    d[s[0]]+=1
  else:
    d[s[2]] += 1
if d['A'] == d['B'] or d['A'] == d['C'] or d['B'] == d['C']:
  print("Impossible")
else:
  list_d = list(d.items())
  list_d.sort(key=lambda i:i[1])
  for i in list_d:
    print(i[0],end='')