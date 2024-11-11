A=int(input())
B=int(A/100)
C=A%100
if 1<=B and B<=12:
 if 1<=C and C<=12:
  print("AMBIGUOUS")
 else:
  print("MMYY")
else:
 if 1<=C and C<=12:
  print("YYMM")
 else:
  print("NA")