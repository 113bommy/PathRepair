n=int(input())
s=[int(input()) for _ in range(n)]
x=sum(s)
if x%10:
  print(x)
else:
  a=[]
  for i in s:
    if i%10:
      a.appned(i)
  if a:
    print(x-min(a))
  else:
    print(0)
  