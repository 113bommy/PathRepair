x=int(input())
while 1:
  for i in range(2,int(x**0.5+1)):
    if x%i==0:
      x+=1
      break
  else:
    print(x)
    exit()