n = int(input())
list = []  
for i in range(1,n+1):
  a = int(input())
  list.append(a)
print(list)
for i in list:
  if i == 2:
    print("2")
  elif (i % 2) == 0:
    print("0")
  else:
    print ("1")