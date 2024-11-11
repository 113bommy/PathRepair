x,y,z=map(int,input().split())
if((min(x,y)+z)>=max(x,y) and z!=0):
    print("?")
else:
    if(x>y):
        print("+")
    elif(x==y):
        print("0")
    else:
        print("-")