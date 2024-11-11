A,B=map(int, input().split())
if (A+12)%14 > (B+12)%14:
  print("Alice")
elif A==B:
  print("Draw")
else:
  print("Bob")