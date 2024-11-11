a = input()
b=int(a[0:2])
c=int(a[2:4])
if 1<=b<=12 & 1<=c<=12:
    print('AMBIGUOUS')
elif 1<=b<=12 :
    print('MMYY') 
elif 1<=c<=12:
    print('YYMM')
else:
    print('NA')
