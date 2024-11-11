from math import sqrt
n=int(input())
q=int(sqrt(n))
k=t=1
for i in range(1,q+1):
   if n%i==0:
      t=i
   k=max(k,t)
print(k,n//k)
   
   
