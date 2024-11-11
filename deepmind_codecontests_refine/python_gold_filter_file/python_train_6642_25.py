s=input()
s1=int(s[0:2])
s2=int(s[2:4])

if 0<s1<13 and 0<s2<13:
    print("AMBIGUOUS")
elif 0<s1<13:
    print("MMYY")
elif 0<s2<13:
    print("YYMM")
else:
    print("NA")