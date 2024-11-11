s=input()
x=len(s)-7
for i in range(x+1):
  if s[:i]+s[x+i:] == "keyence":
    print("YES")
    break
else:
  print("NO")