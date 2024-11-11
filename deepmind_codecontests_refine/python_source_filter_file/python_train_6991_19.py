x,y,z=map(int,input().split())
if(x>y):
    if(y+z>=x):
        print("?")
    else:
        print("+")
elif(y>x):
    if(x+z>=y):
        print("?")
    else:
        print("-")
elif(x==y and z%2==0):
    print(0)
else:
    print("?")
