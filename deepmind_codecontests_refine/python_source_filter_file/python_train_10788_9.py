n = eval(input())
i = 0
c = 0
d = 0
f1 = True
f2 = True
while i<n :
  k = input().split(" ")
  x = int(k[0])
  y = int(k[1])
  i += 1
  if x>0:
    d =+ 1
  elif x<0: 
    c += 1  
  if c>1:  
    f1 = False
  if d>1:
    f2 = False
if(f1 or f2 ):
  print("Yes")
else:
  print("No")