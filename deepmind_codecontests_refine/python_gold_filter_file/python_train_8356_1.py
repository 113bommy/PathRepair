t = int(input())
for i in range(t):
    n = int(input())

    if(n%3==0):
        z = n//3
        print(z,0,0)
    elif(n%5==0):
        z = n//5
        print(0,z,0)
    elif(n%7==0):
        z=n//7
        print(0,0,z)
    else:

        if((n-3)%5==0 and n-3>0):
            z = (n-3)//5
            print(1,z,0)
        elif((n - 3) % 7 == 0 and n-3>0):
            z = (n-3) // 7
            print(1, 0, z)
        elif ((n - 5) % 3 == 0 and n-5>0):
            z = (n-5)// 3
            print(z, 1, 0)
        elif ((n - 5) % 7 == 0 and n-5>0):
            z = (n-5) // 7
            print(0, 1, z)

        elif ((n - 7) % 3 == 0 and n-7>0):
            z = (n-7)// 3
            print(z, 0, 1)
        elif ((n - 7) % 5 == 0 and n-7>0):
            z = (n-7) // 5
            print(0, z, 1)
        else:
            print(-1)
