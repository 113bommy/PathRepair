s=input()
if "C"in s and "F"in s:
  if s.index("C")<s.rindex("F"):
    print("Yes")
    exit()
print("No")