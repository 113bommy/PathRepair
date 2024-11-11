s=input()
f=int(s[:2])
b=int(s[2:])
if 0<f<13 and 0<b<13:
    print('AMBIGUOUS')
elif 0<b<13:
    print('YYMM')
elif 0<f<13:
    print('MMYY')
else:
    print('NA')