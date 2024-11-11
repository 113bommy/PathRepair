y_b_r = list(map(int,input().rstrip().split()))

y,b,r = y_b_r[0],y_b_r[1],y_b_r[2]


if (r-1) <= b:
    print(1)
    if (r-2) <= y:
        print(r+(r-1)+(r-2))
    elif (r-2) > y:
        print((y+2)+(y+1)+y)
elif (r-1) > b:
    print(2)
    if (b-1) <= y:
        print((b+1)+b+(b-1))
    elif (b-1) > y:
        print((y+2)+(y+1)+y)


