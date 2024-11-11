import math

t=int(input())
k=0
while(k != t):
  A=int(input())
  if(A<10):
    A=(10*(A%10-1)+1)
  elif(A>=10 and A<100):
    A=(10*(A%10-1)+3)
  elif(A>=100 and A<1000):
    A=(10*(A%10-1)+6)
  elif(A>=1000 and A<10000):
    A=(10*(A%10-1)+10)
  print(A)
  k=k+1