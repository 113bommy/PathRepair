n1 = input()
n2 = input()
index = 0
for i in n1:
  if i == '0' :
    index += 1
  else:
    break  
n1 = n1[index : len(n1)]
index = 0
for i in n2:
  if i == '0':
    index += 1
  else:
    break  
n2 = n2[index : len(n2)]
print(n1 , n2)
if len(n1) > len(n2):
  print(">")
elif len(n2) > len(n1):
  print("<")
else:
  for i in range(len(n1)):
    if n1[i] > n2[i]:
      print(">")
      break
    elif n2[i] > n1[i]:
      print("<")
      break
  else:
    print("=")   