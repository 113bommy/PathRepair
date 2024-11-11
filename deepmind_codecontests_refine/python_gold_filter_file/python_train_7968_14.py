side = int(input())
if side>=3:
    if side%2:
        print((side**2-1)//2, (side**2+1)//2)
    else:
        print((side**2-4)//4, (side**2+4)//4)
else:
    print(-1)
