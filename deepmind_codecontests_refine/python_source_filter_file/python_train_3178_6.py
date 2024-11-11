import math
n,b,p=map(int,input().split())
y=p*n
c=0
while(n>2):
    c+=int(n//2)
    n=(n//2)+(n%2) 
c+=1
x=int(((2*b)+1)*c)
print(x,y)