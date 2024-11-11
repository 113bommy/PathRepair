X=int(input())
b=X**0.5
if all(X%i!=0 for i in range(2,int(b)+1)):
  X+=1
else:
  print(X)