s=int(input())
x=s//11*2
if s%11>0:
  x+=1
if s%11>5:
  x+=1
print(x)