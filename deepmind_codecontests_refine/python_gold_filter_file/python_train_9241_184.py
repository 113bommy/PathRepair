n=int(input())
s=input()

if len(s)<=n:
  print(s)
else:
  print(s[:n]+"...")