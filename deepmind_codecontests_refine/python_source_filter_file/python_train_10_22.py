n = int(input())
for i in range(0,n):
    a = list(map(int,input().split()))

    if(a[0] == a[2] or a[0] == 1):
        num = a[1] +1
        if(a[1] == a[2] and a[0] == a[1]):
            print("2")
        elif(a[1] == 1):
            print(a[2])
        elif(a[2] % a[1] == 0):
            print(a[1]+a[2])
        else:
                while(1):
                        if(num % a[2] == 0):
                                print(num)
                                break
                        num += 1
    else:
        num = a[2]
        while(1):
                if num not in range(a[0],a[1]+1):
                        print(num)
                        break
                num += a[2]
