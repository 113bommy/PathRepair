x=int(input())
y=x//3
if y%3==0:
    if x%3==0:
        print(y-2," ",y+1," ",y+1)
    elif x%3==1:
        print(y-2," ",y+1," ",y+2)
    else:
        print(y-2," ",y+2," ",y+2)
else:
    if x%3==0:
        print(y," ",y," ",y)
    elif x%3==1 and y%3!=2:
        print(y," ",y," ",y+1)
    elif x%3==1 and y%3==2:
        print(y-1," ",y-1," ",y+3)
    elif x%3==2 and y%3!=2:
        print(y," ",y+1," ",y+1)
    elif x%3==2 and y%3==2:
        print(y," ",y," ",y+2)
