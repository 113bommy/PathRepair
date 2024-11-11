s = input()
for i in [s, s[:len(s)//2], s[len(s)//2+1:]]:
  if i != i[::-1]:
    print("No")
  break
else:
  print("Yes")