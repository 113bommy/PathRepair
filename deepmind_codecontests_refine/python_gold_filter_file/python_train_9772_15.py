S=set(list(input()))
n=0
s=0
e=0
w=0
if 'N' in S:
  n=1
if 'S' in S:
  s=1
if 'E' in S:
  e=1
if 'W' in S:
  w=1

if (n^s)|(e^w):
  print('No')
else:
  print('Yes')