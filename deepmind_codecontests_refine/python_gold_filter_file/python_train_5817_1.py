s = input()
a = ""
for i in s:
  if i == "1" or i == "0":
    a += i
  else:
    if a:
      a = a[:-1]
print(a)