s = input()
t = {}
p = 0
z = 0
for i in s:
  if i in t:
    t[i]+= 1
  else:
    t[i] = 1
for k in t:
  if t[k] > 1:
    p = int(t[k])**2
    z += p
if(t[k] == 1):
  print(len(s))
else:
  print(z)