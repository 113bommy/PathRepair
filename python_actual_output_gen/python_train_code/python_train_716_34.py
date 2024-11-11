s = input()
o = s[::2]
e = s[1::2]

co = 'L' in o
ce = 'R' in e

if co or ce:
  print('Yes')
else:
  print('No')