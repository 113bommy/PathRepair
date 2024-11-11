a=input()
b=len(a)
r=int(a)
if b<2:
 k=r%4
 if k==0 :
  print(4)
 elif k==1 :
  print(0)
 elif k==2 :
  print(0)
 else :
  print(0)
else :
 c=int(a[-2:])
 
 i=c%4
 if i==0 :
  print(4)
 elif i==1 :
  print(0)
 elif i==2 :
  print(0)
 else :
  print(0)