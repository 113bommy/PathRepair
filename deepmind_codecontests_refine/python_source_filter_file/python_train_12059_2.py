a,b=map(int,input().split())
if a==1 and b==1:
  print(1)
elif a==1 or b==1:
  print(max(a,b)-2)
else:
  print(a+a+b+b-8)