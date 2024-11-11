x=int(input())
p=x**0.5
while any(x%i==0 for i in range(2,int(p)+1)):
  x+=1
else:
  print(x)