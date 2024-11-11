s=int(input())
k=input()
if len(k) <=s:
  print(k)
else:
  print(k[:s] + '...')