n = int(input())
if(n==0):
    print(0)
else:
    if(n%4 == 1):
        print(8)
    elif(n%4 == 2):
        print(4)
    elif(n%4 == 3):
        print(2)
    else:
        print(6)