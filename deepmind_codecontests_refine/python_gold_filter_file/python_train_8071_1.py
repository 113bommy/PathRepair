mod = 1000000007
resp = 1

def between(c, l, r):
  return ord(c) >= ord(l) and ord(c) <= ord(r)

s = input()

for i in s:
  if between(i, '0', '9'):
    i = ord(i) - ord('0')
  elif between(i, 'A', 'Z'):
    i = ord(i) - ord('A') + 10
  elif between(i, 'a', 'z'):
    i = ord(i) - ord('a') + 36
  elif i == '-':
    i = 62
  else:
    i = 63
  for j in range(6):
    if((i>>j)&1) == 0:
      resp = (3*resp) % mod

print(resp)