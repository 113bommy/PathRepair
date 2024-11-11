q = int(input())
bookList = dict()
rc = 0
lc = 0
RL = []
LL = []
for qi in range(q):
    Type, ID = input().split(" ")
    ID = int(ID)
    if Type=="L":
        if qi==0:
            RL.append(ID)
            bookList[ID] = ["R", rc]
            rc += 1
        else:
            LL.append(ID)
            bookList[ID] = ["L", lc]
            lc += 1
    elif Type=="R":
        RL.append(ID)
        bookList[ID] = ["R", rc]
        rc += 1
    else:
        point = bookList[ID]
        if point[0]=="R":
            idx = point[1]+lc
        else:
            idx = lc-point[1]-1
        left = idx
        right = lc+rc-idx-1
        print(min(left, right))
