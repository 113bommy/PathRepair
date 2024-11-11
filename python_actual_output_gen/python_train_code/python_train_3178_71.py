a = int(input())
s = input()
if len(s) > a:
  print(s[:a+1]+"...")
else:
  print(s)