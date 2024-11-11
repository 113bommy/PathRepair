for i in range(int(input())):
    a=[int(i) for i in list(input())]
    flag0=0
    flag3=0
    flag2=0
    x=0
    counter=0
    for i in a:
        if i==0:
            flag0=1
            counter+=1
        if counter>1:
            if i%2==0:
                flag2=1
        if counter==1 or counter==0:
            if i%2==0 and i!=0:
                flag2=1
        x+=i
    if x%3==0:
        flag3=1
    if flag2==1 and flag0==1 and flag3==1:
        print("red")
    else:
        print("cyan")