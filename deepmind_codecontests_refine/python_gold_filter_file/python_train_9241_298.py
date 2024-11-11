n = int(input())
s = input()
if n >= len(s):
  print(s)
else:
  print(s[:n]+"...")