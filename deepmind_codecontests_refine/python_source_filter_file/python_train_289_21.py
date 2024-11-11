s = str(input())
num = len(s)
for i in range(n):
  for j in range(i,n):
    if s[:i] + s[k:] == "keyence":
      print("YES")
      exit()
print("NO")