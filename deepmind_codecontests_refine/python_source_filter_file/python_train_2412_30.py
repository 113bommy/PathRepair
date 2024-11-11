def findx(n):
    m = n-1

    for x in range(1, int((n)**0.5)):
        if m % x == 0:
            z = n - x**2 - x -1
            
            if z % (2*x) == 0:
                print(x, z // (2*x))
                return 
    
    print("NO")

findx(19)
# findx(int(input()))


