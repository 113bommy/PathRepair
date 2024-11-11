for _ in range(int(input())):
    x=input()
    t=0
    for i in range(1,len(x)):
        if x[i]!=x[i-1]:
            # print(x[i])
            t=1
            break
    if t==1:
        n=len(x)
        print('01'*(n))
    else:
        print(x)