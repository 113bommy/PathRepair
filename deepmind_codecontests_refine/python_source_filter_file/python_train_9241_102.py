k = int(input())
s = input()

if len(s) >= k:
  print(s[0:7] + "...")
else:
  print(s)