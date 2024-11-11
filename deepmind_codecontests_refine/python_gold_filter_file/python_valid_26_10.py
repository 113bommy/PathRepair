for _ in range(int(input())):
    a=input()
    l1=[a[x] for x in range(0,10,2)]
    l2=[a[x] for x in range(1,10,2)]
    if (l1[0:3].count("1")+l1[0:3].count("?")==3 and l2[0:3].count("0")+l2[0:3].count("?")==3) or (l2[0:3].count("1")+l2[0:3].count("?")==3 and l1[0:3].count("0")+l1[0:3].count("?")==3):
        print(6)
    elif (l1[0:4].count("1")+l1[0:4].count("?")>l2[0:3].count("1")+2) or (l2[0:3].count("1")+l2[0:3].count("?")>l1[0:4].count("1")+1):
        print(7)
    elif (l1[0:4].count("1")+l1[0:4].count("?")>l2[0:4].count("1")+1) or (l2[0:4].count("1")+l2[0:4].count("?")>l1[0:4].count("1")+1):
        print(8)
    elif (l1.count("1")+l1.count("?")>l2[0:4].count("1")+1) or (l2[0:4].count("1")+l2[0:4].count("?")>l1.count("1")):
        print(9)
    else:
        print(10)
                                                            
