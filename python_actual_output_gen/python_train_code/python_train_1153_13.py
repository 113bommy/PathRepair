A,B = map(int,input().split())
if (A+B)%3==0 or A>=3 or B >=3:
  print("Possible")
else:
  print("Impossible")