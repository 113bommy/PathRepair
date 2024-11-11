n = int(input("ew"))
for i in range(n):
  x = input("e")
  if len(x)>10:
    s = len(x) - 2
    print(x[0]+str(s)+x[-1])
  else:
    print(x)  