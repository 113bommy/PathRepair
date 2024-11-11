n = int(input())
s = input()

if len(s) >= n:
  print(s[0:n] + "...")
else:
  print(s)