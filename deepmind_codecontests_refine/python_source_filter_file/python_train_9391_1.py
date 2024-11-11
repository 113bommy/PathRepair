for _ in range(int(input())):
    a, b , c, r = list(map(int, input().split()))

    dis = abs(b-a)

    # outside
    if((c > a and c>b) or (c<a and c < b)):
        z = min(abs(c-a), abs(c-b))
        if z >= r:
            print(dis)
        elif (z < r):
            if((dis +z -r) < 0):
                print(0)
            else:
                print(dis+z - r)
    #  inside
    elif((c>a and c < b) or (c<a and c>b)):
        z = min(abs(c-a), abs(c-b))
        if(r >=max(abs(c-a), abs(c-b))):
            print(0)
        elif(r > z and r < max(abs(c-a), abs(c-b))):
            print(max(abs(c-a), abs(c-b)))
        elif(r <= z):
            print(dis - 2*r)
    elif(c == a or c == b):
        ans = dis-r
        if(ans < 0):
            print(0)
        else:
            print(ans)

