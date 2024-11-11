a,b = map(int, input())
if a%3 and b%3 and (a+b)%3:
  print("Impossible")
else:
  print("Possible")