import math 
n=int(input())
if n%2==0:
    print('NO')
elif n==1:
    print('NO')
else:
    x=1
    y=((n-1)//2 - 1)        
    print(x,y,end=" ") 