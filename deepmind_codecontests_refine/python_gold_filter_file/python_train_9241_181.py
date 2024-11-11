n=int(input())
k=input()
if len(k)<=n:
  print(k)
else:
  a=k[:n]
  print(a+"...")