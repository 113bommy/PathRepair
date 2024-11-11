a,b=map(int,input().split())

if (a-1)%13>(b-1)%13:
  print("Alice")
elif (a-1)%13<(b-1)%13:
  print("Bob")
else:
  print("Draw")