import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
n = int(cont.pop(0)[0])

if n%2:
    #if odd
    level = n // 2 + 1

    print(6*level + 5)
    #first draw the 4 diags
    for i in range(level):
        print(i+2,i+1)
    for i in range(level+1):
        print(i+1,i+1)
        print(i+2,i)
    for i in range(level):
        print(i+3,i)

    #connector
    for i in range(level+2):
        print(0,i+1)
        if (i,level+2) != (0,5):
            print(i,level+2)


else:
    #if even
    level = n // 2

    print(6*level + 14)
    #draw the 4 diags
    for i in range(level+1):
        print(1+i,i+1)
        print(1+i+1,i+1)
        print(1+i+1,i)
        print(1+i+2,i)
    #now the connector
    for i in range(level+3):
        print(0,i+1)
    for i in range(1,level+5):
        print(i,level+3)
    for i in range(3):
        print(level+4,level+i)
