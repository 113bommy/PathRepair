y,b,r=input().split()
y=int(y)
b=int(b)
r=int(r)
a=min(y,b,r)
if r==a :
    print(3*r-3)
elif b==a :
    print(3*b)
elif y==a :
    if r>b :
        print(3*y+3)
    elif r>=y+2 :
        print(3*y+3)
    else :
        print(3*y)
        
    
    
