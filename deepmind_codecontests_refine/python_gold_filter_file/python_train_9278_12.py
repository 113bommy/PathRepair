import math
n=int(input())
if(n==1):
    print('2')
elif(n==2):
    print('3')
else:
    x=math.sqrt(n)
    y=math.floor(x)
    if(x==y):
        print(y*2)
    else:
        z=y*y +y
        if(n<=z):
            print(y*2+1)
        else:
            print(y*2 + 2)