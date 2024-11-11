s=input()
a=int(s[:2])
b=int(s[2:])
if 0<a<13 and 0<b<13:
    print("AMBIGUOUS")
elif 0<=a and 0<b<13:
    print("YYMM")
elif 0<=b and 0<a<13:
    print("YYMM")
else:
    print("NA")