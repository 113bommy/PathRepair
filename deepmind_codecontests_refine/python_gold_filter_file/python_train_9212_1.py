x1,y1,x2,y2,x3,y3 = map(int,input().split(" "))
if (x1==x2==x3==(y1+y2+y3)):
    print(x1)
    for i in range(y1):
        print("".join(["A"]*x1))
    for i in range(y2):
        print("".join(["B"]*x1))
    for i in range(y3):
        print("".join(["C"]*x1))
elif (x1==x2==y3==(y1+y2+x3)):
    print(x1)
    for i in range(y1):
        print("".join(["A"]*x1))
    for i in range(y2):
        print("".join(["B"]*x1))
    for i in range(x3):
        print("".join(["C"]*x1))
elif (x1==y2==x3==(y1+x2+y3)):
    print(x1)
    for i in range(y1):
        print("".join(["A"]*x1))
    for i in range(x2):
        print("".join(["B"]*x1))
    for i in range(y3):
        print("".join(["C"]*x1))
elif (x1==y2==y3==(y1+x2+x3)):
    print(x1)
    for i in range(y1):
        print("".join(["A"]*x1))
    for i in range(x2):
        print("".join(["B"]*x1))
    for i in range(x3):
        print("".join(["C"]*x1))
elif (y1==y2==y3==(x1+x2+x3)):
    print(y1)
    for i in range(x1):
        print("".join(["A"]*y1))
    for i in range(x2):
        print("".join(["B"]*y1))
    for i in range(x3):
        print("".join(["C"]*y1))
elif (y1==y2==x3==(x1+x2+y3)):
    print(y1)
    for i in range(x1):
        print("".join(["A"]*y1))
    for i in range(x2):
        print("".join(["B"]*y1))
    for i in range(y3):
        print("".join(["C"]*y1))
elif (y1==x2==y3==(x1+y2+x3)):
    print(y1)
    for i in range(x1):
        print("".join(["A"]*y1))
    for i in range(y2):
        print("".join(["B"]*y1))
    for i in range(x3):
        print("".join(["C"]*y1))
elif (y1==x2==x3==(x1+y2+y3)):
    print(y1)
    for i in range(x1):
        print("".join(["A"]*y1))
    for i in range(y2):
        print("".join(["B"]*y1))
    for i in range(y3):
        print("".join(["C"]*y1))
#1
elif (x1==x2+x3==y1+y2==y1+y3):
    print(x1)
    for i in range(y1):
        print("".join(["A"]*x1))
    for i in range(y2):
        print("".join(["B"]*x2+["C"]*x3))
elif (x1==x2+y3==y1+y2==y1+x3):
    print(x1)
    for i in range(y1):
        print("".join(["A"]*x1))
    for i in range(y2):
        print("".join(["B"]*x2+["C"]*y3))
elif (x1==y2+x3==y1+x2==y1+y3):
    print(x1)
    for i in range(y1):
        print("".join(["A"]*x1))
    for i in range(x2):
        print("".join(["B"]*y2+["C"]*x3))
elif (x1==y2+y3==y1+x2==y1+x3):
    print(x1)
    for i in range(y1):
        print("".join(["A"]*x1))
    for i in range(x2):
        print("".join(["B"]*y2+["C"]*y3))
elif (y1==y2+y3==x1+x2==x1+x3):
    print(y1)
    for i in range(x1):
        print("".join(["A"]*y1))
    for i in range(x2):
        print("".join(["B"]*y2+["C"]*y3))
elif (y1==y2+x3==x1+x2==x1+y3):
    print(y1)
    for i in range(x1):
        print("".join(["A"]*y1))
    for i in range(x2):
        print("".join(["B"]*y2+["C"]*x3))
elif (y1==x2+y3==x1+y2==x1+x3):
    print(y1)
    for i in range(x1):
        print("".join(["A"]*y1))
    for i in range(y2):
        print("".join(["B"]*x2+["C"]*y3))
elif (y1==x2+x3==x1+y2==x1+x3):
    print(y1)
    for i in range(x1):
        print("".join(["A"]*y1))
    for i in range(y2):
        print("".join(["B"]*x2+["C"]*x3))
#2
elif (x2==x1+x3==y1+y2==y2+y3):
    print(x2)
    for i in range(y2):
        print("".join(["B"]*x2))
    for i in range(y1):
        print("".join(["A"]*x1+["C"]*x3))
elif (x2==x1+y3==y1+y2==y2+x3):
    print(x2)
    for i in range(y2):
        print("".join(["B"]*x2))
    for i in range(y1):
        print("".join(["A"]*x1+["C"]*y3))
elif (x2==y1+x3==x1+y2==y2+y3):
    print(x2)
    for i in range(y2):
        print("".join(["B"]*x2))
    for i in range(x1):
        print("".join(["A"]*y1+["C"]*x3))
elif (x2==y1+y3==x1+y2==y2+x3):
    print(x2)
    for i in range(y2):
        print("".join(["B"]*x2))
    for i in range(x1):
        print("".join(["A"]*y1+["C"]*y3))
elif (y2==y1+y3==x1+x2==x2+x3):
    print(y2)
    for i in range(x2):
        print("".join(["B"]*y2))
    for i in range(x1):
        print("".join(["A"]*y1+["C"]*y3))
elif (y2==y1+x3==x1+x2==x2+y3):
    print(y2)
    for i in range(x2):
        print("".join(["B"]*y2))
    for i in range(x1):
        print("".join(["A"]*y1+["C"]*x3))
elif (y2==x1+y3==y1+x2==x2+x3):
    print(y2)
    for i in range(x2):
        print("".join(["B"]*y2))
    for i in range(y1):
        print("".join(["A"]*x1+["C"]*y3))
elif (y2==x1+x3==y1+x2==x2+y3):
    print(y2)
    for i in range(x2):
        print("".join(["B"]*y2))
    for i in range(y1):
        print("".join(["A"]*x1+["C"]*x3))
#3
elif (x3==x2+x1==y1+y3==y2+y3):
    print(x3)
    for i in range(y3):
        print("".join(["C"]*x3))
    for i in range(y1):
        print("".join(["B"]*x2+["A"]*x1))
elif (x3==x2+y1==x1+y3==y2+y3):
    print(x3)
    for i in range(y3):
        print("".join(["C"]*x3))
    for i in range(x1):
        print("".join(["B"]*x2+["A"]*y1))
elif (x3==y2+x1==y1+y3==x2+y3):
    print(x3)
    for i in range(y3):
        print("".join(["C"]*x3))
    for i in range(y1):
        print("".join(["B"]*y2+["A"]*x1))
elif (x3==y2+y1==x1+y3==x2+y3):
    print(x3)
    for i in range(y3):
        print("".join(["C"]*x3))
    for i in range(x1):
        print("".join(["B"]*y2+["A"]*y1))
elif (y3==y2+y1==x1+x3==x2+x3):
    print(y3)
    for i in range(x3):
        print("".join(["C"]*y3))
    for i in range(x1):
        print("".join(["B"]*y2+["A"]*y1))
elif (y3==y2+x1==y1+x3==x2+x3):
    print(y3)
    for i in range(x3):
        print("".join(["C"]*y3))
    for i in range(y1):
        print("".join(["B"]*y2+["A"]*x1))
elif (y3==x2+y1==x1+x3==y2+x3):
    print(y3)
    for i in range(x3):
        print("".join(["C"]*y3))
    for i in range(x1):
        print("".join(["B"]*x2+["A"]*y1))
elif (y3==x2+x1==y1+x3==y2+x3):
    print(y3)
    for i in range(x3):
        print("".join(["C"]*y3))
    for i in range(y1):
        print("".join(["B"]*x2+["A"]*x1))
else:
    print(-1)

