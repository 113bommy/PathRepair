n=int(input())

x=n//11
y=n%11
if y==0:
  y=0
elif y<6:
  y=1
else:
  y=2

print(x*2+y)