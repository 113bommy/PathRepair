s = input()
t = input()
m = set()
d = dict()
v = True
for i in range(len(s)):
  if s[i] != t[i]:
    if s[i] not in m and t[i] not in m:
      a = t[i]
      for j in range(len(t)):
        if t[j] == s[i]:
          t = t[:j] + a + t[j+1:len(t)]
        elif t[j] == a:
          t = t[:j] + s[i] + t[j+1:len(t)] 
      m.add(s[i])
      m.add(a)
      d[s[i]] = a
    else:
      print(-1)
      v = False
      
  else:
    m.add(s[i])
if v:
  print(len(d))
  for i, x in d.items():
    print(i, x)