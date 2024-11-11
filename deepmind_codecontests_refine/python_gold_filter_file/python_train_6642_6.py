S = input()
f = int(S[:2])
s = int(S[2:])
if 1 <= f <= 12:
  if 1 <= s <= 12:
    print('AMBIGUOUS')
  else:
    print('MMYY')
elif 1 <= s <= 12:
  print('YYMM')
else:
  print('NA')
