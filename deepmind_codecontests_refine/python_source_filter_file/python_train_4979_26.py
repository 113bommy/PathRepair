a,b = map(int,input().split())
if a+b==15 or a*b==15:
    if a*b==15:
        print("X")
    else:
        print("+")
else:
    print("x")