for _ in range(int(input())):
    n,m=map(int,input().split())
    if(n<m):
        print("0")
    elif(n==m):
        print("1")
    else:
        arr=[]
        tt=0
        for i in range(1,11):
            p=m*i
            tt+=(p%10)
            arr.append(tt)
        #print(arr)
        e=n//m
        ft=e//10
        cf=e%10
        if(cf!=0):
            print((ft*arr[9])+arr[cf-1])
        else:
            print(ft*arr[9])