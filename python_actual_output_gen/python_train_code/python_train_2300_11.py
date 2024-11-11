a = input()
if 0<int(a[:2])<=12:
  if int(a[2:])<=12:
    print("AMBIGIUOUS")
  else:
    print("MMYY")
else:
  if int(a[2:])<=12:
    print("YYMM")
  else:
    print("NA")