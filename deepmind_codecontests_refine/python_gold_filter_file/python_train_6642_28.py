s=int(input())
x=s%100
y=s//100
print(("AMBIGUOUS" if 0<x<13 else "MMYY") if 0<y<13 else "YYMM" if 0<x<13 else "NA")