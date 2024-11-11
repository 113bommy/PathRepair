A,B=map(int,input().split())
if A==1:
  A=20
if B==1:
  B=20
if A>B:
  print("Alice")
elif A==B:
  print("Draw")
else:
  print("Bob")