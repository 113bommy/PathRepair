n = int(input())
s = str(input())
if len(s) <= n:
  print(s)
else:
  print(s[:k+1]+"...")