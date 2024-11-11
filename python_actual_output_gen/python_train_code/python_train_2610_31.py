s = open(0).read().split()
x = s[0][0]
s[0] = s[0][1:]
 
while True:
  p = ord(x)-97
  if len(s[p] == 0):
    print(x.upper())
    break
  x = s[p][0]
  s[p] = s[p][1:]