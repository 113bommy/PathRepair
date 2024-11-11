S = input()
n = int('N' in S)
s = int('S' in S)
w = int('W' in S)
e = int('E' in S)

if n + s == 1 or w + e == 1:
  print('No')
else:
  print('Yes')