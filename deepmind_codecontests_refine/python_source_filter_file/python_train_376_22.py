def factorial(n):
  if n==0:
    return 0
  elif n==1:
    return 1
  else:
    return n*factorial(n-1)
	
friend1=int(input())
friend2=int(input())
if friend1>friend2:
  friend1,friend2=friend2,friend1
mid=(friend2-friend1)/2
if not mid.is_integer():
  tiredness=(factorial((friend2-friend1)//2))+(factorial(((friend2-friend1)//2)+1))
  
else:
  tiredness=2*(factorial((friend2-friend1)//2))
  
print(tiredness)