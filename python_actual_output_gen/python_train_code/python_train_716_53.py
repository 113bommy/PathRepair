s=list(input())
if not("L" in s[::2]):
  if not("R" in s[1::2]):
    print("Yes")
else:
  print("No")