a=int(input())
if a>2800:
  print("AGC")
else:
  print("ABC" if a<1200 else "ARC")