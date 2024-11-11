a,b,c,d=map(int,input().split())
x=int((a+d-1)/d)
y=int((c+b-1)/b)
 
if x>=y:
  print("yes")
else:
  print("no")