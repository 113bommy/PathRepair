n=int(input())
x=10**18
k=(774*x)%n
def inv(a):
  for i in range(a):
    if i*n+1==(i*n+1)//a*a:
      return (i*n+1)//a
      
if n%9==0:
  offset=k//9
elif n%3==0:
  n//=3
  k//=3
  offset=(k*inv(3))%n
else:
  offset=(k*inv(9))%n
l=x-1-offset
r=10*x-1-offset
print(str(l)+" "+str(r))