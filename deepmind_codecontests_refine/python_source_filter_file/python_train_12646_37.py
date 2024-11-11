n = int(input())
s = str(input()).lower()
d = ""

if len(s) < 26:
  print("NO")
else:
  for i in range(n):
    if s[i] not in d:
      d += s[i]

if len(d) >= 26:
  print("YES")
else:
  print("NO")