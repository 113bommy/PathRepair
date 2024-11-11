k=int(input())
s=input()
t=len(s)
if t<=k:
  print(s)
else:
  print(s[:k] + '...')