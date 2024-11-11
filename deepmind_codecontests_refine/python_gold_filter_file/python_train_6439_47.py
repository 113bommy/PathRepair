a, b = map(int,input().split())
a, b = a+13*(a<2),b+13*(b<2)
if a>b:
  print("Alice")
elif a<b:
  print("Bob")
else:
  print("Draw")
