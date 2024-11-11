def user(name):
  newName = ""
  count = 0
  for ch in name:
    if count == 0:
      newName  += ch.upper()
    else:
      newName += ch
    count += 1
  print(newName)


user(input())