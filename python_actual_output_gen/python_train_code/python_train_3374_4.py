for i in range(int(input())):
    l = list(map(int, input().split() ))
    l.sort()
    if l[0]!=l[1]:
        l[0] = int(l[0])+1
    else:
        if l[2]-l[1]>1:
            l[0] = int(l[0])+1
            l[1] = int(l[1])+1            

    if l[1]!=l[2]:
        l[2] = int(l[2])-1
    else:
        if l[1]-l[0]>1:
            l[1] = int(l[1])-1
            l[2] = int(l[2])-1

    ans = (l[1]-l[0] ) +(l[2]-l[1]) + (l[2]-l[0])
    print(ans)