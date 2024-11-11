s = input()
a = "1"
for i in range(int(input())):
  if s[i] != "1":
    a = s[i]
    break
print(a)