x,y,z=map(int,input().split())
if abs(x-y)>z:
    if x>y:
        print("+")
    elif y>x:
        print("-")
else:
    if x==y and z==0:
        print("0")
    else:
        print("?")
    
