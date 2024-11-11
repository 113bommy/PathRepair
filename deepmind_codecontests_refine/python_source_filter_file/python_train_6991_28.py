x,y,z = map(int, input().split())
if(x>y):
    print("+")
elif(y>x):
    print("-")
else:
    if(z==0):
        print(0)
    else:
        print("?")
