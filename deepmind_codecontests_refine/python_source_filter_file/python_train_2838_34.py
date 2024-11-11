t=int(input())
for j in range(t):
    x,y,z=[int(x) for x in input().split()]
    if x==y and x==z:
        print("YES")
        print(x, y, z)
    elif x==y and z<x:
        print("YES")
        print(x, z, z-1)
    elif x==z and y<x:
        print("YES")
        print(y, x, y-1)
    elif y==z and x<z:
        print("YES")
        print(x-1, x, z)
    else:
        print("NO")