x,y,z = map(int,input().split())
if x == y:
    if z == 0:
        print(0)
    else:
        print("?")
elif x > y:
    if z > x-y:
        print("?")
    elif z < x-y:
        print("+")
    else:
        print("?")

else:
    if z > y-x:
        print("?")
    elif z < y-x:
        print("-")
    else:
        print("?")