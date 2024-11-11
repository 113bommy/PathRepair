t = int(input())
for i in range(t):
    n = int(input())
    if(n==2):
        print(1)
    elif(n==3):
        print(7)
    elif(n%2==0):
        a = int(n/2)
        for j in range(a):
            print(1,end='')
    else:
        print(7,end='')
        a = int(n/2)-1
        for j in range(a):
            print(1,end='')
    print()

