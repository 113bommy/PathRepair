S = input()
b = 0 < int(S[0:2]) < 12
a = 0 < int(S[2:]) < 12

if b and a:
    print("AMBIGUOUS")
elif b:
    print("MMYY")
elif a:
    print("YYMM")
else:
    print("NA")