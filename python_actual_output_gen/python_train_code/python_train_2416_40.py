x,y,z=map(int,input().split(" "))
if(z==0):
    if(x>y):
        print("+")
    if(x<y):
        print("-")
    if(x==y):
        print("0")        

elif(z!=0):
    if(x>=y):
        if(x-y>z):
            print("+")
        if(x-y<=z):
            print("?")
    if(y>x):
        if(y-x>z):
            print("-")
        if(x-y<z):
            print("?")
