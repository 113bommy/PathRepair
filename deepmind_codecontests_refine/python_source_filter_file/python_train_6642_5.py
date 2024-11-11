s=input()
if 0<int(s[:2])<=12 and 0<int(s[2:])<=12:
    print("AMBIGUOUS")
elif 0<int(s[:2])<=12:
    print("YYMM")
elif 0<int(s[2:])<=12:
    print("MMYY")
else:
    print("NA")