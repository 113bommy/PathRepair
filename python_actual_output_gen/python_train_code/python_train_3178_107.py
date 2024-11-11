n=int(input())
k=input()
if len(k)<=n:
  print(k)
else:
  a=k[0:n+1]
  print(a+"...")