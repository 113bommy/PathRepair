a=input()
a_i=int(a[0:2])
b_i=int(a[2:4])
if 0<a_i<=12 and 0<b_i<=12:
    print('AMBIGUOUS')
elif 0<b_i<=12:
    print("YYMM")
elif 0<a_i<=12:
    print("MMYY")
else:
    print("NA")