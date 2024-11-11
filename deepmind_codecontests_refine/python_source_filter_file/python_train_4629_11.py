import sys

n=int(input())
if n<4:
  print("NO")
  sys.exit()
print("YES")
if n%2==0:
  print("1 * 2 = 2")
  print("3 * 4 = 12")
  print("12 * 2 = 24")
  if n>4:
    print("6 - 5 = 1")
    for i in range(7,n,2):
      print(i+1, "-", i, "= 1")
      print("1 * 1 = 1")
  print("24 * 1 = 24")
if n%2==1:
  print("5 - 2 = 3")
  print("3 - 1 = 2")
  print("3 * 2 = 6")
  print("6 * 4 = 24")
  if n>5:
    print("7 - 6 = 1")
    for i in range(8,n,2):
      print(i+1, "-", i, "= 1")
      print("1 * 1 = 1")
  print("24 * 1 = 24")
  


  