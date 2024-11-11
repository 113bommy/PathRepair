n=int(input())
if(n==1):
  print(4)
elif(n<=36):
  print("8"*(n//2),"0"*(n%2),sep='')
else:print(-1)