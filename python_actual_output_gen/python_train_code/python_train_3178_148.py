k=int(input())
s=input()
l=len(s)
if l<=k:
  print(s)
else:
  print(s[:k-1]+"...")