while 1:
    if int(input())==0:break
    n=list(map(int,input().split()))
    b=len(n)
    a=sum(n)/b
    print((sum((x-a)**2 for x in n)/b)**0.5)