for _ in range(int(input())):
    n=int(input())
    lst=[int(i) for i in input().split()]
    ne=0
    no=0
    lste=[]
    lsto=[]
    for i in lst:
        if i%2==0:
            ne+=1
            lste.append(i)
        else:
            no+=1
            lsto.append(i)
    if ne%2==0 and no%2==0:
        print('YES')
    else:
        nk=0
        for i in lste:
            if (i+1) in lsto or (i-1) in lsto:
                print('YES')
                nk=1
                break
        if nk==1:
            print('NO')
