n1,x1=input().split()
n=int(n1)
x=int(x1)
s=0
if n>x:
  for i in range(1,x+1):
      if(x%i==0):
        s+=1
else:
  for i in range(2,n+1):
       if(x%i==0) and (x/i<=n):
        s+=1
print(s)