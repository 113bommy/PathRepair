a = int(input())
for _ in range(a):
    z = int(input())
    if z <= 1:
       print("-1")
    elif z%2 == 0:
        for i in range(int(z/2)):
            print("59",end = '')
        print()
    else:
        for i in range(int((z-1)/2)):
            print("95",end = '')
        print("9")
