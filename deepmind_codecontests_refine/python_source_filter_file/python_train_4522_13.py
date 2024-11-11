def fun(x1,y1,x2,y2):
    if abs(x2-x1)==abs(y2-y1):
        print(abs(x2-x1))
    elif abs(x2-x1)==0 and abs(y2-y1)>0:
        print(abs(y2-y1))
    elif abs(x2-x1)>0 and abs(y2-y1)==0:
        print(abs(x2-x1))
    elif abs(x2-x1)>0 and abs(y2-y1)>0 and abs(x2-x1)!=abs(y2-y1):
        print(abs(y2-y1)+abs(x2-x1)-1)

    while x1-x2!=0 or y1-y2!=0:
        if x1-x2<0 and y1-y2==0:
            x1=x1+1
            print("D")
        if x1-x2>0 and y1-y2==0:
            x1=x1-1
            print("U")
        if x1-x2==0 and y1-y2<0:
            y1=y1+1
            print("R")
        if x1-x2==0 and y1-y2>0:
            y1=y1-1
            print("L")
        if x1-x2>0 and y1-y2>0:
            x1=x1-1
            y1=y1-1
            print("LU")
        if x1-x2>0 and y1-y2<0:
            x1=x1-1
            y1=y1+1
            print("RU")
        if x1-x2<0 and y1-y2<0:
            x1=x1+1
            y1=y1+1
            print("RD")
        if x1-x2<0 and y1-y2>0:
            x1=x1+1
            y1=y1-1
            print("LD")
    return 
    

a=input()
b=input()
Dict = {'a':1,'b':2,'c':3,'d':4,'e':5,'f':6,'g':7,'h':8} 
y1=Dict.get(a[0])
x1=9-int(a[1])
y2=Dict.get(b[0])
x2=9-int(b[1])
fun(x1,y1,x2,y2)

