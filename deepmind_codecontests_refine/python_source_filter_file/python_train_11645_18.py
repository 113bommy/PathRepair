N,a,b=map(int, input().split())
if a>b:
  print(0)
elif a<b and N==1:
  print(0)
else:
  print(b*2-a*2+1)