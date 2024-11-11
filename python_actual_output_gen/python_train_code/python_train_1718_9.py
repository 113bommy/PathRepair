a,b = map(int,input().split())
if a+b==15 or a*b==15:
    if a*b==15:
        print("+")
    else:
        print("*")
else:
    print("x")