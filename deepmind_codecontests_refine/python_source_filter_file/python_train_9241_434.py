k = int(input())
s = str(input())

if len(s)>k:
  print(s[0:k],"...")
else:
  print(s)