a=int(input())
for i in range(9):
 if a%(9-i)==0 and a/(9-i)<10:
  print("yes")
  break
else:
 print("no")