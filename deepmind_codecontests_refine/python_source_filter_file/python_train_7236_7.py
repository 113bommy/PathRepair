def f(a,b,c):
    if a>=min(b,c) and a<=max(c,b):
        return True


x1,y1=map(int,input().split())
x2,y2=map(int,input().split())
x3,y3=map(int,input().split())
if (x1==x2 and x2==x3) or (y1==y2 and y2==y3):
    print(1)
elif (x1==x2 or x2==x3 or x1==x3 or y1==y2 or y1==y3 or y2==y3):
    if(x1==x2 and f(y3,y1,y2)):
        print(3)
    elif(x2==x3 and(f(y1,y2,y3))):
        print(3)
    elif(x1==x3 and(f(y2,y1,y3))):
        print(3) 
    elif(y1==y2 and f(x3,x1,x2)):
        print(3)
    elif(y2==y3 and(f(x1,x2,x3))):
        print(3)
    elif(y1==y3 and(f(x2,x3,x1))):
        print(3)              
    else:
        print(2)
else:
    print(3)        