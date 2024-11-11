n=int(input())
s=(input())
l=len(s)
if n<=l:
  print(s)
else:
  print(s[0:n]+"...")
