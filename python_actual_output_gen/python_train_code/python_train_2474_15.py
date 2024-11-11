s = input()
for i in [s, s[:len(s)], s[len(s)+1:]]:
  if i != i[::-1]:
    print("No")
  break
else:
  print("Yes")