x,y,z=[int(a) for a in input().split()]
if x==z:
    print("YES")
    quit()
xx=x
while xx<z:
    xx=xx+y
    if xx==z or xx+1==z:
        print("YES")
        quit()
if xx==z or xx+1==z:
    print("YES")
else:
    print("NO")