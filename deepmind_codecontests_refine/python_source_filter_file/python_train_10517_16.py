while 1 :
    x,y,z=[int(i) for i in input().split()]
    if x==y==z==-1:
        break
    if x==-1 or y==-1:
        print('F')
    elif x+y>=80:
        print('A')
    elif x+y>=65:
        print('B')
    elif x+y>=50:
        print('C')
    elif x+y>30:
        if z>=50:
            print('C')
        else:
            print('D')
    else:
        print('F')