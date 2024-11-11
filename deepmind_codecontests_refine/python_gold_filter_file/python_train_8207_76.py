n=int(input())
if n%11>6:
  print(n//11*2+2)
elif n%11>0:
  print(n//11*2+1)
else:
  print(n//11*2)
