a=input()
x=0
b=0
for i in a:
  if i=="T" and x<=-1:
    x+=1
  elif i=="S":
    x-=1
    
  if x==0:
    b+=1
print(b*2)