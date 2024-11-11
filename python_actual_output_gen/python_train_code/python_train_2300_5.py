s = input()
x = int(s[:2])
y = int(s[2:])
if 0<x<=12 and 0<y<=12:
  print('AMBIGUOUS')
elif 0<x<=12:
  print('MMYY')
elif 0<=y<=12:
  print('YYMM')
else:
  print('NA')