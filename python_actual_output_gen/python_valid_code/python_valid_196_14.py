m,n=map(int,input().split())
red=(2*m)//n
green=(5*m)//n
blue=(8*m)//n

if ( (2*m)%n!=0):
    red+=1
if( (5*m)%n!=0):
    green+1
if((8*m)%n!=0):
    blue+=1
    
print(red+blue+green)
