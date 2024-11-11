(n,k) = map(int, input().split())
slogan = input()

banner = [None for n in range(0,n)]

if(k < n/2): #move left
    for i in range(k - 1, -1, -1):
        print("LEFT")
    for i in range(0, n):
        print("PRINT " + slogan[i])
        if(i < n -1):
            print("RIGHT")
else:
    for i in range(k, n):
        print("RIGHT")
    for i in range(n - 1, -1, -1):
        print("PRINT " + slogan[i])
        if(i > 0):
            print("LEFT")
