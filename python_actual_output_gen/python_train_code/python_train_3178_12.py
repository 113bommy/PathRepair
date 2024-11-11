s=int(input())
k=input()
if len(s) <=k:
  print(s)
else:
  print(s[:k] + '...')