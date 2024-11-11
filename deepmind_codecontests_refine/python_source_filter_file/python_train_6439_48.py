A,B=map(int, input().split())
if (A+12)%13 > (B+12)%13:
  print("Alice")
elif A==B:
  print("Draw")
else:
  print("Bob")