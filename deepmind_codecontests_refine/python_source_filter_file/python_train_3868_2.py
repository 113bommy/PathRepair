n = int(input())
m = -1e9
for k in range(len(str(n)) - 1):
  tmp = str(n)
  st = tmp[:k]
  if tmp[k] != '0' and tmp[k] != '1':
    st += chr(ord(tmp[k]) - 1)
  elif tmp[k] == '0':
    st += '9'
  st += "9" * (len(tmp) - k - 1)
  '''if tmp[k] != '0':
    st = tmp[:k] + chr(ord(tmp[k]) - 1) + "9" * (len(tmp) - k - 1)'''
  if n > int(st):
    pr = 1
    print(st)
    for i in range(len(st)):
      pr *= int(st[i])
    if pr > m:
      m = pr
pr = 1
tmp = str(n)
for i in range(len(tmp)):
  pr *= int(tmp[i])
if pr > m:
  print(pr)
else:
  print(m)