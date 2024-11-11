a,b = map(int,input().split())
if a%3==0 | b%3==0 | (a+b)%3==0:
  print("Possible")
else:
  print("Impossible")