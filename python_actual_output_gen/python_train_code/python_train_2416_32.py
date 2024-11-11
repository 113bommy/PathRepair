x,y,z=map(int,input().split())
if abs(x-y)>z:
    if x>y:
        print("+")
    elif y>x:
        print("-")
else:
    if x==y:
        print("0")
    else:
        print("?")
    
