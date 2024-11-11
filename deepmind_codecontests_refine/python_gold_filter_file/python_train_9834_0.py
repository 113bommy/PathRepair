n = int(input())

print ("+------------------------+")



if n>4:
    if (n-4)%3 == 0:
        r1 = 1 + (n-4)//3
        r2 = r1
        r3 = r1 
    elif (n-4)%3 == 1:
        r1 = 2 + (n-4)//3
        r2 = 1 + (n-4)//3
        r3 = r2
    else:
        r1 = 2 + (n-4)//3
        r2 = r1
        r3 = 1 + (n-4)//3

    print ("|",end="")
    for i in range(r1):
        print("O.",end="")
    for i in range(11-r1):
        print("#.",end="")
    print ("|D|)")
    print ("|",end="")
    for i in range(r2):
        print("O.",end="")
    for i in range(11-r2):
        print("#.",end="")
    print ("|.|")
    print ("|O.......................|")
    print ("|",end="")
    for i in range(r3):
        print("O.",end="")
    for i in range(11-r3):
        print("#.",end="")
    print ("|.|)")
    print ("+------------------------+")
else:
    if n == 0:
        r1= 0
        r2 = 0
        r3 = 0
    elif n == 1:
        r1 = 1
        r2 = 0
        r3 = 0
    elif n == 2 or n == 3:
        r1 = 1
        r2 = 1
        r3 = 0
    elif n == 4:
        r1 = 1
        r2 = 1
        r3 = 1
    print ("|",end="")
    for i in range(r1):
        print("O.",end="")
    for i in range(11-r1):
        print("#.",end="")
    print ("|D|)")
    print ("|",end="")
    for i in range(r2):
        print("O.",end="")
    for i in range(11-r2):
        print("#.",end="")
    print ("|.|")
    if n <3:
        print ("|#.......................|")
    else:
        print("|O.......................|")
    print ("|",end="")
    for i in range(r3):
        print("O.",end="")
    for i in range(11-r3):
        print("#.",end="")
    print ("|.|)")
    print ("+------------------------+")