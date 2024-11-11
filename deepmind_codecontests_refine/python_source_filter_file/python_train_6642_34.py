s=input()
f=int(s[:2])
b=int(s[2:])
if f<13 and b<13:
    print('AMBIGUOUS')
elif 0<b<13:
    print('YYMM')
elif f<13:
    print('MMYY')
else:
    print('NA')