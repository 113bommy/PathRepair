s=input()

n1=int(s[:2])
n2=int(s[2:])

if n1<=12 and n2<=12:
    print("AMBIGUOUS")
elif 0<n1<=12:
    print("MMYY")
elif 0<n2<=12:
    print("YYMM")
else:
    print("NA")