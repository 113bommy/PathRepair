for _ in " "*int(input()):
    a,b=map(int,input().split());c=[];d=1
    for i in map(int,input().split()):
        if (i&1):c+=[d]
        d+=1
    z=len(c)
    if z<b:print("NO")
    else:
        if (z&1==b&1):
            print("YES")
            for i in range(b-1):
                print(c[i],end=" ")
            print(a)
        else:print("NO")





