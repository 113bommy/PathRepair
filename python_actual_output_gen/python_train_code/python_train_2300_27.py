A=int(input())
B=int(A/100)
C=A/100
if 1<=B and B<=12:
 if 1<=C and C<=12:
  print("AMBIGUOUS")
 else:
  print("YYMM")
else:
 if 1<=C and C<=12:
  print("MMYY")
 else:
  print("NA")