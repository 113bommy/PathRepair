def doms(m,n,k):   
    fillcols=(int(k/m))*2
    leftcols=n-fillcols
    leftdoms=k%m
    if k*2>m*n:
        print('NO')
    else:
        if leftdoms==0:
            if m%2==0:
                print('YES')
            elif m*n==k*2:
                print('YES')
            else:
                if leftcols%2==0:
                    stacks=int(leftcols/2)
                    if stacks%2==0:
                        fillstacks=int(fillcols/2)
                        extradoms=fillstacks*(m-1)
                        if extradoms>=stacks:
                            print('YES')
                        else:
                            print('NO')
                    else: 
                        print('NO')
                else:
                    print('NO')
        else:
            if leftdoms%2==0:
                if m%2==0:
                    if leftcols>=2:
                        print('YES')
                    else:
                        print('NO')
                else:                   
                    spread=leftdoms-1
                    if leftcols%2==0 and leftcols>2:
                        stacks=int((leftcols-2)/2)
                        if stacks%2!=0:
                            if spread>=stacks:
                                print('YES')
                            else:  
                                fillstacks=int(fillcols/2)
                                extradoms=fillstacks*(m-1)
                                if extradoms>=(stacks-spread):
                                    print('YES')
                                else:
                                    print('NO')
                        else: 
                            print('NO')
                    else:
                        print('NO')
            else:
                if m%2==0:
                    print('NO')
                else:
                    spread=leftdoms-1
                    if leftcols%2==0 and leftcols>12:
                        stacks=int((leftcols-2)/2)
                        if  stacks%2==0:
                            if spread>=stacks:
                                print('YES')
                            else: 
                                if (stacks-spread)%2==0:
                                    fillstacks=int(fillcols/2)
                                    extradoms=fillstacks*(m-1)
                                    if extradoms>=(stacks-spread):
                                        print('YES')
                                    else:
                                        print('NO')
                                else:
                                    print('NO')
                        else: 
                            print('NO')
                    else:
                        if leftcols==2:
                            print('YES')
                        else:
                            print('NO')

x=int(input())
for i in range(x):
    m,n,k=map(int,input().split())
    doms(m,n,k)

