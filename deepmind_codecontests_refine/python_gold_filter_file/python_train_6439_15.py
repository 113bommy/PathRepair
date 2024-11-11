a,b=map(int,input().split())

if (a+11)%13>(b+11)%13:
  print("Alice")
elif (a+11)%13<(b+11)%13:
  print("Bob")
else:
  print("Draw")