l = input()
for i in range(len(l)-1):
  if l[i:i+2] == "AC":
    print("Yes")
    break
else:
  print("No")
  