S=input()
s1=int(S[0:2])
s2=int(S[3:5])

if 1<=s1<=12:
    print("AMBIGUOUS" if 1<=s2<=12 else "MMYY")
else:
    print("YYMM" if 1<=s2<=12 else "NA")