from math import factorial 
a=int(input())
s=0
l=0
while 1:
    s+=5
    c=s*5
    d=-1
    while 1:
        l+=1
        d=d+1
        c=c//5
        if (c//5)%5!=0:
            break
    if l>=a :
        break
if l!=a:
    print('0')
else : 
    print('5')
    print(s,s+1,s+2,s+3,s+4)
