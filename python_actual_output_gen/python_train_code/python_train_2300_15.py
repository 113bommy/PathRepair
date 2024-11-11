s = int(input())
s1 = s//100
s2 = s%100

if 0<s1<13 and 0<s2<13:
  print('ANBIGUOUS')
elif 0<s1<13:
  print('MMYY')
elif 0<s2<13:
  print('YYMM')
else:
  print('NA')
