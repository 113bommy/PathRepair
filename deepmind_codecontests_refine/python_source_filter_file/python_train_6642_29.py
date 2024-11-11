n=str(input())
a=int(n[0]+n[1])
b=int(n[2]+n[3])
if 1<=a<=12 and 1<=b<=12:
  print('AMBIGUOUS')
elif 1<=a<=12:
  print('YYMM')
elif 1<=b<=12:
  print('MMYY')
else:
  print('NA')