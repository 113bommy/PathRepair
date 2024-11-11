n = int(input())
for i in range(n):
    x,y,z = map(int,input().split())
    if x == y == z:
        print("YES")
        print(x,y,z)
    elif x == y and z != y:
        if z > y:
            print("NO")
        else:
            print("YES")
            a = x
            b = z
            c = z-1
            print(a,b,c)
    elif x == z and y!=z:
        if y > z:
            print("NO")
        else:
            print("YES")
            b = x
            a = y
            c = y-1
            print(a,b,c)
    elif y == z and x!= y:
        if x>y:
            print("NO")
        else:
            print("YES")
            c = z
            b = x-1
            a = x
            print(a,b,c)
    else:
        print("NO")