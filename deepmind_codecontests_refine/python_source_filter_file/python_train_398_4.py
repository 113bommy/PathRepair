s = input()
is s[::-1].translate(str.maketrans("bdpq","dbqp")) == s:
  print("Yes")
else:
  print("No")