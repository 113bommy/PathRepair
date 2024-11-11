s = input()

l = 0<int(s[:2])<13
r = 0<int(s[2:])<13

if l == 1:
  print('AMBIGUOUS' if r == 1 else 'MMYY')
else:
  print('YYMM' if r == 1 else 'NA')