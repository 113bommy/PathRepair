for i in range(int(input())):
    a,b=map(int,input().split())
    d=(max(a,b)-min(a,b))//2
    if (a+b)%2==1:
        print(a+b-d+1-d)
        for i in range(d,a+b+1-d):
            if i==a+b-d:
                print(i)
                continue
            print(i,end=' ')
    else:
        print(a+b-d-d)
        for i in range(d,a+b+1-d,2):
            if i==a+b-d:
                print(i)
                continue
            print(i,end=' ')        