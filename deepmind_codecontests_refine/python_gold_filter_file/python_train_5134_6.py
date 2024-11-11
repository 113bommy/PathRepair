import math
def checkprime(x):
    for j in range(2,math.ceil(math.sqrt(x))+1):
        if(x%j==0):
            return (j)
    return x
x=int(input())
y=checkprime(x)

if y==x:
    print(1,0,sep='\n')
else:
    y1=x/y
    if checkprime(y1)==y1:
        print(2)
    else:
        print(1,y*checkprime(y1),sep="\n")
        

      
