A=input()
B,C=int(A[0:2]),int(A[2:4])
if 1<=B<=12 and 1<=C<=12:
    print("AMBIGUOUS")
elif 1<=B<=12:
    print("MMYY")
elif 1<=C<=12:
    print("YYMM")
else:
    print("NA")