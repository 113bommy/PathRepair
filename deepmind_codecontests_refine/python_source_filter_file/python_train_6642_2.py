S=input()
a,b=int(S[:2]),int(S[2:])
if 0<a<13 and b<13:
    print('AMBIGUOUS')
elif 0<a<13:
    print('MMYY')
elif 0<b<13:
    print('YYMM')
else:
    print('NA')