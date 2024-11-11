a = int(input())
for x in range (a):
  y = int(input())
  if y % 6 == 0:
    print(y / 6)
  else:
    print(int(y/6)+1)