S = input()
T = str(S)
A=int(T[0:2])
B=int(T[2:4])
if 1<=A<=12:
  if 1<=B<=12:
    print('AMBIGUOUS')
  else:
    print('MMYY')
elif 1<=B<=12:
    print('YYMM')
else:
    print('NA')